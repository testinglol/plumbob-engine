
void __thiscall FUN_005f76cc(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = param_2;
  FUN_005d499c(param_2);
  (**(code **)(*param_1 + 0x168))();
  param_1[0x69] = 0xc;
  iVar4 = *(int *)(param_1[0x36] + 0x1c);
  iVar2 = *piVar3;
  iVar2 = (**(code **)(*DAT_006f2aa4 + 0x68))(iVar2,piVar3[1] - iVar2);
  param_1[0x6a] = iVar2;
  iVar2 = (**(code **)(*(int *)(&DAT_006f2a74)[param_1[0x69]] + 0x58))();
  param_1[0x4a] = iVar2;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = param_1[0x6a];
  iVar4 = (iVar4 / 4 + -1) / 2 + -10;
  param_2 = (int *)0x0;
  param_1[0x47] = param_1[0x47] + iVar4;
  param_1[0x49] = param_1[0x49] + iVar4;
  iVar2 = ((-param_1[0x20] - param_1[0x4a]) + param_1[0x22]) / 2;
  param_1[0x48] = param_1[0x48] + iVar2;
  param_1[0x4a] = param_1[0x4a] + iVar2;
  piVar3 = param_1 + 0x48;
  if (param_1[0x48] < 1) {
    piVar3 = (int *)&param_2;
  }
  param_1[0x48] = *piVar3;
  piVar1 = param_1 + 0x4a;
  param_2 = (int *)(param_1[0x22] - param_1[0x20]);
  piVar3 = piVar1;
  if (param_1[0x22] - param_1[0x20] <= *piVar1) {
    piVar3 = (int *)&param_2;
  }
  *piVar1 = *piVar3;
  iVar4 = (param_1[0x49] + iVar4 * 2) - param_1[0x47];
  if (iVar4 != param_1[0x21] - param_1[0x1f]) {
    FUN_00512c83(((param_1[0x21] - param_1[0x1f]) - iVar4) / 2,0);
    FUN_004ec186(iVar4);
  }
  return;
}

