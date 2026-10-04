
void __thiscall
FUN_005e491a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  int iVar2;
  
  FUN_005dda18(param_2,param_3,param_4,param_5);
  if (*(int *)(param_1 + 0xd8) == 0) {
    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0x7c);
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x88);
    iVar1 = *(int *)(param_1 + 0x100);
    iVar2 = *(int *)(param_1 + 0xfc);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + -iVar1;
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -iVar2;
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -iVar2;
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -iVar1;
  }
  return;
}

