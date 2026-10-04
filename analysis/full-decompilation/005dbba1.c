
void FUN_005dbba1(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    iVar3 = param_1[2];
    uVar4 = param_1[3];
    puVar5 = param_1;
    while (iVar3 < (int)puVar5[-2]) {
      *puVar5 = puVar5[-4];
      puVar5[1] = puVar5[-3];
      puVar5[2] = puVar5[-2];
      puVar5[3] = puVar5[-1];
      puVar5 = puVar5 + -4;
    }
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5[2] = iVar3;
    puVar5[3] = uVar4;
  }
  return;
}

