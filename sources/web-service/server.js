const hapi = require('hapi');
const exec = require('child_process').exec

const server = new hapi.Server({ 
    host : '0.0.0.0', 
    port : 3000
});

server.route({   
    method  : 'GET',   
    path    : '/database',   
    handler : async (request, h) => {
        try
        {
            const status = await service()

            const output = status.stdOut
            const lines  = output.split('\n').filter( item => item != '' )
            const result = lines.map( item => {
                let row = item.split(',').map(item => item.trim())
                row[2] = isNaN(row[2]) ? row[2] : parseInt(row[2])
                return row
            })

            return result
        }
        catch(err)
        {
            console.log(err);
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
        return err; 
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

        const process = exec('router --reset', function(error, stdout, stderr) { 
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
