import lineReader from 'line-reader';

const colors = {};
const graph = {};

function parseInputLine(line) {
    const edges = [];
    const words = line.split(' ');
    if (words.length === 2) {
        return edges;
    }

    const destColor = `${words[0]}-${words[1]}`;

    for (let words_i=2; words_i<words.length; words_i += 2) {
        const srcColor = `${words[words_i]}-${words[words_i + 1]}`;
        edges.push([srcColor, destColor]);
    }
    return edges;
}

function addColor(color) {
    colors[color] = {
        isVisited: false,
        isShinyGold: color === 'shiny-gold'
    };
}

function addEdge(edge) {
    if (typeof graph[edge[0]] === 'undefined') {
        graph[edge[0]] = [];
    }

    graph[edge[0]].push(edge[1]);
}

lineReader.eachLine('input.txt', (line, last) => {
    const edges = parseInputLine(line);
    edges.forEach(edge => {
        addColor(edge[0]);
        addColor(edge[1]);

        addEdge(edge);
    });

    if(last){
        let ans = 0;
        let toBeVisited = ['shiny-gold'];
        while (toBeVisited.length !== 0) {
            const srcColor = toBeVisited.pop();
            if (!colors[srcColor].isVisited) {
                ans++;
                colors[srcColor].isVisited = true;
                colors[srcColor].isShinyGold = true;
                if (graph[srcColor]) {
                    toBeVisited = toBeVisited.concat(graph[srcColor]);
                }
            }
        }

        console.log(ans - 1);
    }
});
