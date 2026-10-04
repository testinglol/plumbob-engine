
int __thiscall FUN_004607ee(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_00460a05(param_2);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x70);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_2 + 0x74);
  *(undefined1 *)(param_1 + 0x78) = *(undefined1 *)(param_2 + 0x78);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_2 + 0x80);
  *(undefined1 *)(param_1 + 0x84) = *(undefined1 *)(param_2 + 0x84);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_2 + 0x88);
  *(undefined2 *)(param_1 + 0x8c) = *(undefined2 *)(param_2 + 0x8c);
  *(undefined1 *)(param_1 + 0x8e) = *(undefined1 *)(param_2 + 0x8e);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 0x90);
  *(undefined2 *)(param_1 + 0x94) = *(undefined2 *)(param_2 + 0x94);
  uVar1 = *(undefined4 *)(param_2 + 0x98);
  puVar3 = (undefined4 *)(param_2 + 0xc);
  puVar4 = (undefined4 *)(param_1 + 0xc);
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x98) = uVar1;
  return param_1;
}

