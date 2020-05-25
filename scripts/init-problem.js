const rootDir = './';
const fs = require('fs');

const cppProblemTemplate =
		'#include <iostream>\n\n#define ll long long\n#define ull unsigned long long\n\nusing namespace std;\n\nint main() {\n\treturn 0;\n}\n';

function padZeros(num, size) {
		const s = "000000000" + num;
		return s.substr(s.length-size);
}

try {
		let count = 0;
		fs.readdirSync(rootDir)
				.filter(file => file.includes('problem-'))
				.forEach(file => {
						const serial = parseInt(file.replace('problem-', ''));
						if(serial > count) {
								count = serial;
						}
				});

		const newSerial = count + 1;
		const newSerialString = padZeros(newSerial, 5);
		console.log(`${count} problems found, creating problem-${newSerialString}`);

		if(fs.existsSync(`./problem-${newSerialString}`)) {
				console.error(`ERROR: Directory problem-${newSerialString} already exists.`);
				return;
		}

		fs.mkdirSync(`./problem-${newSerialString}`);

		fs.writeFileSync(
				`./problem-${newSerialString}/problem.md`,
				`Problem: ${newSerial}\n---\n`
		);

		fs.writeFileSync(
				`./problem-${newSerialString}/solution.cpp`,
				cppProblemTemplate
		);
} catch (e) {
		console.error(`ERROR: ${e}`);
}
