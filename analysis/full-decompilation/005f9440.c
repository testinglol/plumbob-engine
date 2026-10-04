
int * __fastcall FUN_005f9440(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  piVar1 = (int *)param_1[0x20];
  local_8 = param_1;
  if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,&local_8), iVar2 != 0)
     ) {
    local_8 = (int *)(**(code **)(*param_1 + 0x90))();
  }
  return local_8;
}

