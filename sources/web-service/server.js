const hapi = require('hapi');
const exec = require('child_process').exec

const server = new hapi.Server({ 
    host : 'localhost', 
    port : 3101, 
});

server.route({   
    method  : 'GET',   
    path    : '/',   
    handler : (request, h) => {
        try
        {
            const status = await service()
            return status.stdOut
        }
        catch
        {
            return 'error'
        }
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


async function service()
{
    return new Promise( (resolve, reject) => {
        const status = {
            exitCode : 0,
            stdOut   : ''
        }

        const process = exec('../../bin/router --reset', function(error, stdout, stderr) { 
            status.stdOut = stdout
            status.stdErr = stderr
            if (status.exitCode != 0)
            {
                reject(status)
            }
            else
            {
                resolve(status)
            }
        })
    
        process.on('exit', function(code) {
            status.exitCode = code
        })
    })
}


launch();
