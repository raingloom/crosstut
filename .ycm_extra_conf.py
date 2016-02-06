import os
import shutil

cwd = os.getcwd()
jsonname='compile_commands.json'
bjsonp=os.path.join(cwd,'build',jsonname)
ljsonp=os.path.join(cwd,jsonname)

#copies database to cwd
if os.path.isfile(bjsonp):
    if os.path.isfile(ljsonp):
        if os.stat(bjsonp).st_mtime > os.stat(ljsonp).st_mtime:
            shutil.copy( bjsonp, ljsonp )
    else
        shutil.copy( bjsonp, ljsonp )

compilation_database_folder = cwd
