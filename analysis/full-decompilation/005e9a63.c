
undefined4 __thiscall FUN_005e9a63(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 local_14 [4];
  int local_10;
  int local_8;
  
  if ((char)param_2 != '\0') {
    iVar1 = **(int **)(param_1 + 0xd8);
    uVar3 = FUN_005d49d6();
    uVar3 = FUN_004096c2(uVar3);
    (**(code **)(iVar1 + 0x50))(local_14,uVar3);
    if (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80) < local_8 - local_10) {
      FUN_004ec1a7(local_8 - local_10);
    }
    cVar2 = (**(code **)(*(int *)(param_1 + 0xd4) + 8))(4);
    if (cVar2 == '\0') {
      FUN_005dd46f(param_2,0);
      uVar3 = FUN_005dd5e1(0xff,0,0xff);
      *(undefined4 *)(param_1 + 0xf8) = uVar3;
      (**(code **)(**(int **)(param_1 + 0x58) + 0x68))(uVar3);
      return 1;
    }
  }
  uVar3 = FUN_005dd46f(param_2,0);
  return uVar3;
}

