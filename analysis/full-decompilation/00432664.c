
void __thiscall FUN_00432664(int param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = FUN_00422665((undefined4 *)(param_1 + 0xf4));
  if (cVar1 == '\0') {
    *param_2 = 1;
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xf4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xf8);
  }
  else {
    *param_2 = 0;
    *(undefined4 *)(param_2 + 8) = 0xfffffff0;
    *(undefined4 *)(param_2 + 4) = 0xfffffff0;
  }
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x110);
  while( true ) {
    iVar2 = 0;
    if (*(short *)(param_1 + 0x66) == 0) {
      iVar2 = FUN_004327c8();
    }
    if (iVar2 == 0) break;
    if (*(short *)(param_1 + 0x66) == 0) {
      param_1 = FUN_004327c8();
    }
    else {
      param_1 = 0;
    }
  }
  uVar3 = FUN_00407498((int)*(short *)(param_1 + 0x7e));
  *(undefined4 *)(param_2 + 0xc) = uVar3;
  iVar2 = (int)*(short *)(param_1 + 0x66);
  *(int *)(param_2 + 0x10) = iVar2;
  if (iVar2 != -1) {
    *(int *)(param_2 + 0x10) = iVar2 + -1;
    if (iVar2 + -1 == -1) {
      *(undefined2 *)(param_1 + 0x66) = 0xffff;
    }
  }
  return;
}

