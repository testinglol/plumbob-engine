
void __fastcall FUN_00533066(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_005de621();
  iVar1 = (**(code **)(*param_1 + 0x18))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
    (**(code **)(*piVar2 + 0x168))();
  }
  return;
}

