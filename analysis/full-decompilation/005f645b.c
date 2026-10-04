
uint __thiscall FUN_005f645b(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  if (param_2 != (int *)0x0) {
    *(int **)(param_1 + 0x108) = param_2;
    if (param_3 != '\0') {
      iVar1 = *param_2;
      uVar3 = FUN_005dd5e1(0xff,0,0xff);
      (**(code **)(iVar1 + 0x68))(uVar3);
    }
    if (*(int *)(param_1 + 0xd4) == 1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x108) + 0x20);
      iVar2 = *(int *)(*(int *)(param_1 + 0x108) + 0x1c);
      *(undefined4 *)(param_1 + 0x10c) = 0;
      *(undefined4 *)(param_1 + 0x110) = 0;
      *(int *)(param_1 + 0x118) = iVar1;
      *(int *)(param_1 + 0x114) = iVar2 / 4;
      FUN_004ec1a7(iVar1 - *(int *)(param_1 + 0x110));
    }
    else {
      if (*(int *)(param_1 + 0xd4) != 2) goto LAB_005f6510;
      iVar1 = *(int *)(*(int *)(param_1 + 0x108) + 0x20);
      *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(*(int *)(param_1 + 0x108) + 0x1c);
      *(undefined4 *)(param_1 + 0x10c) = 0;
      *(undefined4 *)(param_1 + 0x110) = 0;
      *(int *)(param_1 + 0x118) = iVar1 / 4;
      FUN_004ec186(*(undefined4 *)(param_1 + 0x114));
    }
    uStack_8 = 0x1000000;
  }
LAB_005f6510:
  return uStack_8 >> 0x18;
}

