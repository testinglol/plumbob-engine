
int __thiscall FUN_005cb7ff(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_006358b0(param_1,param_2);
  FUN_006358b0(param_1 + 0x40,param_2 + 0x40);
  iVar1 = param_1 + 0xc4;
  if (*(undefined4 **)(param_2 + 0xc0) != (undefined4 *)(param_2 + 0xc4)) {
    iVar1 = param_1 + 0x1c0;
  }
  *(int *)(param_1 + 0xc0) = iVar1;
  puVar2 = (undefined4 *)(param_2 + 0xc4);
  puVar3 = (undefined4 *)(param_1 + 0xc4);
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)(param_2 + 0x1c0);
  puVar3 = (undefined4 *)(param_1 + 0x1c0);
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_2 + 700);
  *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_2 + 0x2c0);
  *(undefined4 *)(param_1 + 0x2c4) = *(undefined4 *)(param_2 + 0x2c4);
  *(undefined4 *)(param_1 + 0x2c8) = *(undefined4 *)(param_2 + 0x2c8);
  *(undefined1 *)(param_1 + 0x2cc) = *(undefined1 *)(param_2 + 0x2cc);
  *(undefined1 *)(param_1 + 0x2cd) = *(undefined1 *)(param_2 + 0x2cd);
  *(undefined1 *)(param_1 + 0x2ce) = *(undefined1 *)(param_2 + 0x2ce);
  puVar2 = (undefined4 *)(param_2 + 0x2d0);
  puVar3 = (undefined4 *)(param_1 + 0x2d0);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}

