import lineReader from 'line-reader';

const colors = {};
const graph = {};

function parseInputLine(line) {
    const edges = [];
    const words = line.split(' ');
    if (words.length === 2) {
        return edges;
    }

    const srcColor = `${words[0]}-${words[1]}`;

    for (let words_i=2; words_i<words.length; words_i += 3) {
        const destColor = `${words[words_i + 1]}-${words[words_i + 2]}`;
        edges.push([srcColor, {
            color: destColor,
            count: parseInt(words[words_i])
        }]);
    }
    return edges;
}

function addColor(color) {
    colors[color] = {
        howManyIn: -1,
        isShinyGold: color === 'shiny-gold'
    };
}

function addEdge(edge) {
    if (typeof graph[edge[0]] === 'undefined') {
        graph[edge[0]] = [];
    }

    graph[edge[0]].push(edge[1]);
}

function howManyIn(color) {
    if (colors[color].howManyIn !== -1) {
        return colors[color].howManyIn;
    }

    if (!graph[color]) {
        colors[color].howManyIn = 0;
        return 0;
    }

    let ans = 0;
    graph[color].forEach(dest => {
        ans += dest.count + (dest.count * howManyIn(dest.color));
    });
    colors[color].howManyIn = ans;
    return ans;
}

lineReader.eachLine('input.txt', (line, last) => {
    const edges = parseInputLine(line);
    edges.forEach(edge => {
        addColor(edge[0]);
        addColor(edge[1].color);

        addEdge(edge);
    });

    if (last) {
        const ans = howManyIn('shiny-gold');
        console.log(ans);
    }
});
