
void __thiscall FUN_005083af(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0xe0) = param_2;
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  iVar1 = *piVar2;
  iVar3 = FUN_004cba72(param_1 + 0xe4);
  (**(code **)(iVar1 + 0x7c))(iVar3,iVar3 >> 0x1f);
  FUN_005084ca();
  return;
}

