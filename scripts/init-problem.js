const fs = require('fs');
const inquirer = require('inquirer');

function padZeros(num, size) {
	const s = "000000000" + num;
	return s.substr(s.length - size);
}

function replaceVars(fileContent, replacements) {
	['PROBLEM_NUMBER', 'PROBLEM_NUMBER_WITH_PADDING', 'PROBLEM_SOURCE'].forEach(variable => {
		fileContent = fileContent.replace(
			new RegExp(`{${variable}}`, 'g'),
			replacements[variable]
		);
	});

	if (replacements['PROBLEM_LINK'] !== '') {
		fileContent = fileContent.replace(/{PROBLEM_LINK}/g, ` | [link](${replacements['PROBLEM_LINK']})`);
	} else {
		fileContent = fileContent.replace(/{PROBLEM_LINK}/g, '');
	}
	return fileContent;
}

function inquireForConfig() {
	return new Promise(((resolve) => {
		inquirer
			.prompt([
				{
					type: 'list',
					name: 'source',
					message: 'What\'s the source of problem?',
					choices: ['AdventOfCode', 'LeetCode', 'DailyCodingProblem.com', 'CodeChef']
				},
				{
					type: 'input',
					name: 'link',
					message: 'Enter link to the problem:',
					default: '',
				},
				{
					type: 'list',
					name: 'language',
					message: 'Choose the language:',
					choices: [
						{name: 'C++', value: 'cpp'},
						{name: 'JavaScript', value: 'js'}
					]
				}
			])
			.then((config) => {
				resolve(config);
			});
	}));
}

(async () => {
	try {
		// Ask user for details of new problem interactively.
		const config = await inquireForConfig();

		// Find existing problems count for determining new problem number.
		// Also detects if any problem has same 'link' as that of this new problem to avoid duplicate.
		let duplicateExists = false;
		let existingProblemsCount = 0;
		fs.readdirSync('./')
			.filter(file => file.includes('problem-'))
			.forEach(file => {
				// Update problems count based on this problem number.
				const number = parseInt(file.replace('problem-', ''));
				if (number > existingProblemsCount) {
					existingProblemsCount = number;
				}

				// Read 'problem.md' file, find link (if present) & check for duplicate
				const problemContent = fs.readFileSync(`./${file}/problem.md`, 'utf8');
				const links = problemContent.match(/\[link\]\(.*\)/g);
				if (links && links[0]) {
					const link = links[0].replace('[link](', '').replace(')', '')
					if (link === config.link) {
						duplicateExists = true;
					}
				}
			});
		if (duplicateExists) {
			console.error("ERROR: Another problem with same link already exists.");
			return;
		}

		// Generate new problem number.
		const problemNumber = existingProblemsCount + 1;
		const problemNumberWithPadding = padZeros(problemNumber, 5);
		console.log(`${existingProblemsCount} problems found, creating problem-${problemNumberWithPadding}`);

		// Check if some problem with similar problem number already exists.
		if (fs.existsSync(`./problem-${problemNumberWithPadding}`)) {
			console.error(`ERROR: Directory problem-${problemNumberWithPadding} already exists.`);
			return;
		}

		// Create new problem directory & write template files to it.
		fs.mkdirSync(`./problem-${problemNumberWithPadding}`);
		fs.readdirSync(`./templates/${config.language}`)
			.forEach(file => {
				const fileContent = fs.readFileSync(`./templates/${config.language}/${file}`, 'utf8');
				fs.writeFileSync(
					`./problem-${problemNumberWithPadding}/${file}`,
					replaceVars(fileContent, {
						PROBLEM_NUMBER: problemNumber,
						PROBLEM_NUMBER_WITH_PADDING: problemNumberWithPadding,
						PROBLEM_SOURCE: config.source,
						PROBLEM_LINK: config.link
					})
				);
			});

		console.log(`problem-${problemNumberWithPadding} created successfully.`);
	} catch (e) {
		console.error(`ERROR: ${e}`);
	}
})();
