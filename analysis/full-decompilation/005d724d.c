
undefined4 __thiscall FUN_005d724d(int param_1,char param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 != '\x01') || (*(int *)(param_1 + 0xd4) == 0)) {
    if (*(HGDIOBJ *)(param_1 + 0xd4) != (HGDIOBJ)0x0) {
      DeleteObject(*(HGDIOBJ *)(param_1 + 0xd4));
      *(undefined4 *)(param_1 + 0xd4) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}

