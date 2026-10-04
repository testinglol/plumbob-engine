
/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00703afc == 1) {
    FUN_00644a79();
  }
  FUN_00644ab2(param_1);
  (*(code *)PTR___exit_006daae0)(0xff);
  return;
}

