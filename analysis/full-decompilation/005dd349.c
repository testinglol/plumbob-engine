
void __fastcall FUN_005dd349(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1[0x16] == 0) {
    param_1[7] = param_1[0x1f];
    param_1[8] = param_1[0x20];
    local_c = param_1[0x21];
    param_1[9] = local_c;
    param_1[10] = param_1[0x22];
    local_10 = param_1[8];
    iVar3 = param_1[7];
    local_8 = param_1[10];
    piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      do {
        iVar2 = (**(code **)(*piVar1 + 0x184))();
        if (iVar2 != 0) break;
        local_10 = local_10 + piVar1[0x20];
        local_8 = local_8 + piVar1[0x20];
        local_c = local_c + piVar1[0x1f];
        iVar3 = iVar3 + piVar1[0x1f];
        piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
      } while (piVar1 != (int *)0x0);
      param_1[7] = iVar3;
      param_1[8] = local_10;
      param_1[9] = local_c;
      param_1[10] = local_8;
    }
  }
  else {
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[10] = param_1[0x22] - param_1[0x20];
    param_1[9] = param_1[0x21] - param_1[0x1f];
    FUN_005dd61d();
  }
  return;
}

