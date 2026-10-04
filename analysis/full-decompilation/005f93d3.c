
int __fastcall FUN_005f93d3(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  piVar1 = *(int **)(param_1 + 0x80);
  if ((piVar1 != (int *)0x0) &&
     (local_8 = param_1, iVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,&local_8), iVar2 == 0)) {
    return local_8;
  }
  return 0x200;
}

