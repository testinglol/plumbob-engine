
void __thiscall FUN_0046cfd5(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0xb0) = param_2;
  puVar4 = (undefined4 *)(param_1 + 0x10);
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)(param_1 + 0x30) = 2;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0x32;
  *(undefined2 *)(param_1 + 0x10) = 1;
  *(undefined2 *)(param_1 + 0x12) = 0xf;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  *(undefined2 *)(param_1 + 0x1e) = 6;
  *(undefined2 *)(param_1 + 0x20) = 0x7cd;
  uVar1 = FUN_0046d641();
  *(undefined2 *)(param_1 + 0x34) = 0xffff;
  *(undefined2 *)(param_1 + 0x18) = uVar1;
  *(short *)(param_1 + 0x2e) = (short)*(char *)(DAT_006e486c + 100);
  *(undefined2 *)(param_1 + 0x42) = 0;
  *(undefined1 *)(param_1 + 0xe1) = 0;
  *(undefined1 *)(param_1 + 0xe0) = 0;
  uVar2 = FUN_0046f546();
  *(undefined4 *)(param_1 + 0xac) = uVar2;
  uVar2 = FUN_004425e2();
  FUN_0046d7b3(uVar2);
  *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(DAT_006e486c + 0x66);
  return;
}

