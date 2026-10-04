
undefined4
FUN_005ca911(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 *param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_2f4 [64];
  undefined1 local_2b4 [128];
  undefined4 *local_234;
  undefined4 local_230 [63];
  undefined4 local_134 [63];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  byte local_28;
  undefined1 local_27;
  byte local_26;
  undefined4 local_24;
  
  _memset(local_2f4,0,0x2f0);
  local_24 = 0x20;
  FUN_006358b0(local_2f4,param_3);
  FUN_006358b0(local_2b4,param_2);
  iVar1 = param_4[2];
  local_234 = local_230;
  puVar4 = local_230;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_4;
    param_4 = param_4 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar4 = local_134;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_5;
    param_5 = param_5 + 1;
    puVar4 = puVar4 + 1;
  }
  if (iVar1 == 0) {
    local_234 = local_134;
  }
  local_38 = *param_1;
  uStack_34 = param_1[1];
  uStack_30 = param_1[2];
  uStack_2c = param_1[3];
  local_27 = 0;
  local_28 = *(byte *)(local_234 + 0x21) & 1;
  local_26 = (byte)(*(uint *)(param_6 + 0x138) >> 0x13) & 1;
  FUN_005cb537(local_2f4);
  iVar1 = (**(code **)(**(int **)(param_6 + 0xa4) + 0x28))
                    (*(int **)(param_6 + 0xa4),&local_38,FUN_005cad14,param_6);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)(param_6 + 0x99c);
    if (((*(byte *)(iVar1 + -0x1b) & 4) != 0) && (*(int *)(iVar1 + -0x14) == 0x10)) {
      *(undefined1 *)(iVar1 + -0x23) = 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

