
void __thiscall FUN_00504075(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((*(char *)(*(int *)(param_1 + 0xfc) + 0xe0) != '\0') &&
       (iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x14), iVar1 != 0)) &&
      ((param_2 == 0 || (((param_2 == 1 || (param_2 == 2)) || (param_2 == 3)))))) &&
     ((((iVar1 == *(int *)(param_1 + 0xf0) || (iVar1 == *(int *)(param_1 + 0xf4))) ||
       (iVar1 == *(int *)(param_1 + 0xf8))) && (*(char *)(param_1 + 0x11c) == '\0')))) {
    FUN_005e46f0(0);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x14) = *(undefined4 *)(param_1 + 0xdc + param_2 * 4);
  if (*(char *)(param_1 + 0x11c) == '\0') {
    FUN_005e46f0(1);
  }
  if (((param_2 == 5) || (param_2 == 6)) || (param_2 == 7)) {
    FUN_00510747(*(undefined4 *)(param_1 + 0x110));
    FUN_00510775(*(undefined4 *)(param_1 + 0x114));
    uVar2 = *(undefined4 *)(param_1 + 0x118);
  }
  else {
    FUN_00510747(*(undefined4 *)(param_1 + 0x104));
    FUN_00510775(*(undefined4 *)(param_1 + 0x108));
    uVar2 = *(undefined4 *)(param_1 + 0x10c);
  }
  FUN_00510489(0,uVar2);
  if (*(char *)(*(int *)(param_1 + 0xfc) + 0xe0) == '\0') {
    FUN_0050fb20(*(undefined4 *)(param_1 + 0x100),param_1);
  }
  return;
}

