import lineReader from 'line-reader';

let ans = 0;

function process(stack, ch, skipMultiplication) {
    switch (ch) {
        case '(':
            stack.push(ch);
            break;
        case ')':
            const num = stack.pop();
            const beforeNum = stack.pop();
            if (beforeNum === '(') {
                process(stack, num, skipMultiplication);
            } else {
                stack.push(beforeNum);
                stack.push(num);
                stack.push(ch);
            }
            break;
        case '+':
            stack.push(ch);
            break;
        case '*':
            stack.push(ch);
            break;
        case ' ':
            break;
        default:
            if (stack.length >= 2 && stack[stack.length - 1] !== '(') {
                const operator = stack.pop();
                const num1 = parseInt(ch);
                const num2 = parseInt(stack.pop());
                if (operator === '*') {
                    if (skipMultiplication) {
                        stack.push(`${num2}`);
                        stack.push(operator);
                        stack.push(ch);
                    } else {
                        process(stack, `${num1 * num2}`, skipMultiplication);
                    }
                } else {
                    process(stack, `${num1 + num2}`, skipMultiplication);
                }
            } else {
                stack.push(ch);
            }
            break;
    }
}

function solve(expression) {
    expression = expression.split(' ');
    const stack = [];
    for (let i=0; i<expression.length; i++) {
        process(stack, expression[i], true);
    }

    const newStack = [];
    for (let i=0; i<stack.length; i++) {
        process(newStack, stack[i], false);
    }

    return parseInt(newStack.pop());
}

lineReader.eachLine('input.txt', (line, last) => {
    while (true) {
        const brackets = line.match(/\(([0-9]|\*| |\+)+\)/g);
        if (brackets === null) {
            break;
        }

        const res = solve(brackets[0].substring(1, brackets[0].length - 1));
        line = line.replace(brackets[0], `${res}`);
    }

    const x = solve(line);
    ans += x;

    if (last) {
        console.log(ans);
    }
});
