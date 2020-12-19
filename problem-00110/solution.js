import lineReader from 'line-reader';

let ans = 0;

function process(stack, ch) {
    switch (ch) {
        case '(':
            stack.push(ch);
            break;
        case ')':
            const num = stack.pop();
            stack.pop();
            process(stack, num);
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
                    process(stack, `${num1 * num2}`);
                } else {
                    process(stack, `${num1 + num2}`);
                }
            } else {
                stack.push(ch);
            }
            break;
    }
}

lineReader.eachLine('input.txt', (line, last) => {
    const stack = [];
    for (let i=0; i<line.length; i++) {
        process(stack, line[i]);
    }

    ans += parseInt(stack.pop());

    if (last) {
        console.log(ans);
    }
});
