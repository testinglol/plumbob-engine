
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004622c4(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1[5] == -1) {
    piVar1 = (int *)*param_1;
    iVar3 = (**(code **)(*piVar1 + 0x208))();
    iVar4 = (**(code **)(*piVar1 + 0x1f8))();
    piVar1 = (int *)*param_1;
    param_1[5] = iVar3 + iVar4;
    iVar3 = (**(code **)(*piVar1 + 0x20c))();
    iVar4 = (**(code **)(*piVar1 + 0x1fc))();
    iVar4 = iVar4 + iVar3;
    param_1[0xc] = 0;
    param_1[6] = iVar4;
    param_1[10] = param_1[5];
    param_1[0xb] = iVar4;
    param_1[0xd] = param_1[5];
    param_1[0xe] = iVar4;
    param_1[0xf] = DAT_006c46f8;
  }
  if (DAT_006c46f0 == 0) {
    dVar2 = 1.0;
  }
  else {
    dVar2 = (double)(DAT_006e5490 - param_1[0x12]) / (double)DAT_006c46f0;
  }
  if (dVar2 < _DAT_00667280) {
    uVar5 = __ftol();
    param_1[7] = uVar5;
    uVar5 = __ftol();
    param_1[8] = uVar5;
    uVar5 = __ftol();
    param_1[9] = uVar5;
  }
  else {
    param_1[4] = 0;
    param_1[7] = param_1[0xd];
    param_1[8] = param_1[0xe];
    param_1[9] = param_1[0xf];
  }
  *param_2 = param_1[7];
  *param_3 = param_1[8];
  *param_4 = param_1[9];
  return;
}

