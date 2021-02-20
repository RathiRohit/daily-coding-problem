const fs = require('fs');
const inquirer = require('inquirer');

function padZeros(num, size) {
    const s = "000000000" + num;
    return s.substr(s.length - size);
}

function replaceVars(fileContent, replacements) {
    ['PROBLEM_NUMBER', 'PROBLEM_NUMBER_WITH_PADDING', 'PROBLEM_SOURCE'].forEach(variable => {
        fileContent = fileContent.replace(
            new RegExp(`{${variable}}`,'g'),
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
        let existingProblemsCount = 0;
        fs.readdirSync('./')
            .filter(file => file.includes('problem-'))
            .forEach(file => {
                const number = parseInt(file.replace('problem-', ''));
                if (number > existingProblemsCount) {
                    existingProblemsCount = number;
                }
            });

        const problemNumber = existingProblemsCount + 1;
        const problemNumberWithPadding = padZeros(problemNumber, 5);
        console.log(`${existingProblemsCount} problems found, creating problem-${problemNumberWithPadding}`);

        if (fs.existsSync(`./problem-${problemNumberWithPadding}`)) {
            console.error(`ERROR: Directory problem-${problemNumberWithPadding} already exists.`);
            return;
        }

        const config = await inquireForConfig();
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
