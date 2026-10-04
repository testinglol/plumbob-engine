
void __thiscall FUN_004cf268(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((*(int *)(param_1 + 0x68) == 8) || (*(int *)(param_1 + 0x68) == 9)) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = '\0';
  }
  if ((param_2 == 8) || (param_2 == 9)) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
  }
  if (((*(int *)(param_1 + 8) == 0) && (cVar1 != cVar3)) && (*(int *)(param_1 + 0x1f0) != 0)) {
    FUN_004b0de0();
  }
  if ((cVar3 != '\0') && (*(int *)(param_1 + 0x48) == 8)) {
    FUN_004cf0ab(1,1);
  }
  *(int *)(param_1 + 0x68) = param_2;
  iVar2 = *(int *)(param_1 + 0x6c + param_2 * 4);
  switch(param_2) {
  case 0:
    if (cRam006f29f9 != '\0') {
      *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 1;
      *(undefined4 *)(param_1 + 0x3c) = 1;
      FUN_004cefd8();
    }
    if ((iVar2 == 0) || (iVar2 = FUN_00492d2c(), iVar2 == 0)) goto LAB_004cf424;
    iVar2 = FUN_00492d2c();
    if (*(int *)(iVar2 + 8) == 0) {
      uVar5 = 0;
      uVar4 = 0;
    }
    else {
      iVar2 = FUN_00492d2c();
      if (*(int *)(iVar2 + 8) == 1) {
        uVar5 = 0;
        uVar4 = 1;
      }
      else {
        iVar2 = FUN_00492d2c();
        if (*(int *)(iVar2 + 8) == 2) {
          uVar5 = 0;
          uVar4 = 4;
        }
        else {
          iVar2 = FUN_00492d2c();
          if (*(int *)(iVar2 + 8) != 3) goto LAB_004cf424;
          uVar5 = 0;
          uVar4 = 0xb;
        }
      }
    }
    break;
  case 1:
    if (cRam006f29f9 != '\0') {
      *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 1;
      *(undefined4 *)(param_1 + 0x3c) = 1;
      FUN_004cefd8();
    }
    if (iVar2 == 0) goto LAB_004cf424;
    iVar2 = FUN_00492d2c();
    if (*(int *)(iVar2 + 8) == 0) {
      uVar5 = 0;
      uVar4 = 9;
    }
    else {
      iVar2 = FUN_00492d2c();
      if (*(int *)(iVar2 + 8) != 1) goto code_r0x004cf3f0;
      uVar5 = 0;
      uVar4 = 10;
    }
    break;
  case 2:
    if (iVar2 == 0) goto LAB_004cf424;
    if (*(int *)(iVar2 + 0x24) == 3) {
      uVar5 = *(undefined4 *)(iVar2 + 0x40);
      uVar4 = 2;
      break;
    }
    goto code_r0x004cf3f0;
  case 3:
    if (iVar2 == 0) goto LAB_004cf424;
    uVar5 = *(undefined4 *)(iVar2 + 0x3c);
    uVar4 = 3;
    break;
  case 4:
    if (cRam006f29f9 != '\0') {
      *(undefined4 *)(param_1 + 0x3c) = 2;
code_r0x004cf3e1:
      *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 1;
      FUN_004cefd8();
    }
  case 5:
  case 8:
  case 9:
    goto code_r0x004cf3ec;
  case 6:
    if (cRam006f29f9 != '\0') {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      goto code_r0x004cf3e1;
    }
    goto code_r0x004cf3ec;
  case 7:
    if (iVar2 == 0) goto LAB_004cf424;
    uVar5 = *(undefined4 *)(iVar2 + 0x44);
    uVar4 = 5;
    break;
  case 10:
    FUN_004cf169(0,0);
    goto LAB_004cf424;
  case 0xb:
    uVar5 = 0xffffffff;
    uVar4 = 7;
    break;
  default:
    goto LAB_004cf424;
  }
  FUN_004cf136(uVar4,uVar5);
LAB_004cf424:
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x10;
  return;
code_r0x004cf3ec:
  if (iVar2 != 0) {
code_r0x004cf3f0:
    uVar5 = FUN_004cba6a();
    FUN_004cf194(uVar5);
  }
  goto LAB_004cf424;
}

