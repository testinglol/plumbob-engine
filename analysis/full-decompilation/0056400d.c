
undefined4 __thiscall FUN_0056400d(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 == 1) {
    iVar4 = 0;
    param_1 = param_1 + 0x42;
    do {
      if ((param_3 != 0) && (param_3 == *param_1)) {
        FUN_00564119(iVar4);
        break;
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 < 4);
    if (iVar4 != 4) {
      return 1;
    }
    param_2 = 1;
LAB_00564038:
    uVar2 = FUN_005e9006(param_2,param_3);
    return uVar2;
  }
  if (param_2 == 0x15) {
    piVar1 = (int *)param_1[0x44];
    piVar3 = piVar1 + 0x5a;
    if (param_3 == -1) {
      if ((char)*piVar3 != '\0') {
        *(char *)piVar3 = '\0';
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar3 = (int *)param_1[0x43];
      if ((char)piVar3[0x5a] == '\0') {
        return 1;
      }
      *(undefined1 *)(piVar3 + 0x5a) = 0;
    }
    else {
      if ((char)*piVar3 != '\x01') {
        *(char *)piVar3 = '\x01';
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar3 = (int *)param_1[0x43];
      if ((char)piVar3[0x5a] == '\x01') {
        return 1;
      }
      *(undefined1 *)(piVar3 + 0x5a) = 1;
    }
    iVar4 = *piVar3;
LAB_005640aa:
    (**(code **)(iVar4 + 0x168))();
  }
  else {
    if (param_2 == 0x1a) {
      uVar2 = 1;
    }
    else {
      if (param_2 == 0x1e) {
        if (param_1[0x4c] != 0) {
          FUN_005448d7(param_3);
        }
        iVar4 = *param_1;
        goto LAB_005640aa;
      }
      if (param_2 != 0x21) goto LAB_00564038;
      uVar2 = 0;
    }
    FUN_00564119(uVar2);
  }
  return 1;
}

