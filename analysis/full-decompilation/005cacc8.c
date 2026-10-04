
int __thiscall FUN_005cacc8(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (param_1 != param_2) {
    FUN_005bfaad(param_2);
    uVar1 = *(undefined1 *)(param_1 + 0xc);
    *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(param_2 + 0xc);
    *(undefined1 *)(param_2 + 0xc) = uVar1;
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_2 + 0x10) = uVar2;
  }
  return param_1;
}

