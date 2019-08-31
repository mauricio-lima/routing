const hapi = require('hapi'); 

const server = new hapi.Server({ 
    host : 'localhost', 
    port : 3101, 
});

server.route({   
    method  : 'GET',   
    path    : '/',   
    handler : (request, h) => {     
        return 'I am the home route'   
    } 
});

const launch = async () => {
    try
    {
        await server.start(); 
    } 
    catch (err) 
    { 
        console.error(err); 
        process.exit(1); 
    };
     
    console.log(`Server running at ${server.info.uri}`); 
}

launch();
