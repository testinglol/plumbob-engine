
void __thiscall FUN_004cb0b0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  FUN_005a5e48(param_2);
  cVar1 = FUN_005a5e72();
  if (cVar1 == '\0') {
    FUN_004cb1a2(0x2d,0x2d);
  }
  else {
    iVar2 = FUN_004096c2();
    iVar2 = *(int *)(iVar2 + 0x1c);
    iVar3 = FUN_004096c2();
    iVar3 = *(int *)(iVar3 + 0x20);
    *(undefined4 *)(param_1 + 0x118) = 0;
    *(undefined4 *)(param_1 + 0x11c) = 0;
    if (iVar2 == 0x2d) {
      *(undefined4 *)(param_1 + 0x114) = 1;
    }
    else if (iVar2 == 0xb4) {
      *(undefined4 *)(param_1 + 0x114) = 4;
    }
    else if (iVar2 == 0x10e) {
      *(undefined4 *)(param_1 + 0x114) = 6;
    }
    else {
      FUN_005a5e48(0);
    }
    if (iVar3 == 0x2d) {
      *(undefined4 *)(param_1 + 0x110) = 1;
    }
    else if (iVar3 == 0x87) {
      *(undefined4 *)(param_1 + 0x110) = 3;
      *(undefined4 *)(param_1 + 0x118) = 1;
    }
    else {
      FUN_005a5e48(0);
    }
    FUN_004cb1a2(iVar2 / *(int *)(param_1 + 0x114),iVar3 / *(int *)(param_1 + 0x110));
  }
  return;
}

