import lineReader from 'line-reader';

let messagesIncoming = false;
const ruleMap = {};
let zeroRegex;
let ans = 0;

function arrToRegex(arr) {
    let regex = '';
    arr.forEach(rule => {
        if (isNaN(parseInt(rule))) {
            regex += `${rule}`;
        } else if (typeof ruleMap[rule] === 'string') {
            regex += `${ruleMap[rule]}`;
        } else {
            preprocessRule(rule);
            regex += `${ruleMap[rule]}`;
        }
    });
    return regex;
}

function preprocessRule(rule) {
    let regex = '';
    ruleMap[rule].forEach((arr, index) => {
        if (index !== 0) {
            regex += '|';
        }
        const tmp = arrToRegex(arr);
        if (tmp.includes('|')) {
            regex += '(';
            regex += tmp;
            regex += ')';
        } else {
            regex += tmp;
        }
    });
    if (regex.length === 1) {
        ruleMap[rule] = regex;
    } else {
        ruleMap[rule] = `(${regex})`;
    }

    if (rule === '8') {
        ruleMap[rule] = `(${ruleMap[rule]}+)`;
    }
}

lineReader.eachLine('input.txt', (line, last) => {
    if (!messagesIncoming && line === '---') {
        preprocessRule('0');
        zeroRegex = new RegExp(`^${ruleMap['0']}$`);
        messagesIncoming = true;
        return;
    }

    if (messagesIncoming) {
        if (zeroRegex.test(line)) {
            ans++;
        }
    }
    else {
        const tokens = line.split(' ');
        ruleMap[tokens[0]] = tokens.slice(1);
        ruleMap[tokens[0]] = ruleMap[tokens[0]].reduce((acc, ch) => {
            if (ch === '|') {
                acc.push([]);
            } else {
                acc[acc.length - 1].push(ch);
            }
            return acc;
        }, [[]]);
    }

    if (last) {
        console.log(ans);
    }
});
