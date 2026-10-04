
void __thiscall FUN_0049c48b(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x80) = 1;
    *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xb0);
    uVar1 = *(undefined4 *)(param_1 + 0xac);
  }
  else if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0x80) = 1;
    *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xb8);
    uVar1 = *(undefined4 *)(param_1 + 0xb4);
  }
  else {
    param_2 = 0;
    *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xa8);
    uVar1 = *(undefined4 *)(param_1 + 0xa4);
    *(undefined1 *)(param_1 + 0x80) = 0;
  }
  *(undefined4 *)(param_1 + 0xd4) = uVar1;
  *(int *)(param_1 + 0xcc) = param_2;
  return;
}

