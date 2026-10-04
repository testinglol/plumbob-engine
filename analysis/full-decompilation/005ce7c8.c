
undefined4 __fastcall FUN_005ce7c8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0xd0) != '\0') {
    piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,9,*(undefined4 *)(param_1 + 0xac));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,4,0);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,7,*(undefined1 *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,0xe,*(undefined1 *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,0x17,4);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,8,*(undefined4 *)(param_1 + 0xb8));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,0x1a,*(undefined1 *)(param_1 + 0xbc));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,0x1d,*(undefined1 *)(param_1 + 0xbd));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,0x1c,*(undefined1 *)(param_1 + 0xbf));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,0x22,*(undefined4 *)(param_1 + 0xc0));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    if (*(char *)(param_1 + 0xbf) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0xc4);
    }
    uVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,4,uVar2);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,5,*(undefined4 *)(param_1 + 200));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,6,*(undefined4 *)(param_1 + 0xcc));
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 100))(piVar1,2,param_1 + 300);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = (**(code **)(*piVar1 + 100))(piVar1,3,param_1 + 0x170);
    *(undefined1 *)(param_1 + 0xd0) = 0;
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
  }
  return *(undefined4 *)(param_1 + 0x5c);
}

