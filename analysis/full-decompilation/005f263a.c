
undefined4 __thiscall FUN_005f263a(int param_1,byte param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x194) == '\0') {
    if (param_2 == 0xd) {
      param_2 = 10;
    }
    if (param_2 == 10) {
      if (*(int *)(param_1 + 0x134) == 1) {
        if (*(int *)(param_1 + 0x48) == 0) {
          return 1;
        }
        FUN_005da644(*(int *)(param_1 + 0x48),3,0x17,param_1,0);
        return 1;
      }
    }
    else if (param_2 < 0x20) {
      return 1;
    }
    iVar1 = param_1 + 0x186;
    *(byte *)(*(int *)(param_1 + 400) + 0x186 + param_1) = param_2;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
    iVar3 = (**(code **)(**(int **)(param_1 + 0x114) + 0x44))(iVar1,*(undefined4 *)(param_1 + 400));
    if (((*(int *)(param_1 + 400) == 1) && (iVar3 == 1)) &&
       (cVar2 = (**(code **)(**(int **)(param_1 + 0x114) + 0x4c))((int)(char)param_2), cVar2 != '\0'
       )) {
      *(undefined1 *)(*(int *)(param_1 + 400) + 0x185 + param_1) = 0x2d;
      *(undefined1 *)(param_1 + 0x194) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x194) = 0;
    }
    if (iVar3 <= *(int *)(param_1 + 400)) {
      *(undefined1 *)(*(int *)(param_1 + 400) + 0x186 + param_1) = 0;
      *(undefined4 *)(param_1 + 400) = 0;
      cVar2 = FUN_005f499f(iVar1);
      if (cVar2 == '\0') {
        FUN_0057a14d(*(undefined4 *)(param_1 + 0x1a8));
      }
      else {
        if (*(int *)(param_1 + 0x13c) == 0) {
          cVar2 = FUN_005f3061(iVar1);
        }
        else if (*(int *)(param_1 + 0x13c) == 1) {
          cVar2 = FUN_005f3220(iVar1);
        }
        else {
          cVar2 = '\0';
        }
        if (cVar2 == '\0') {
          FUN_0057a14d(*(undefined4 *)(param_1 + 0x19c));
        }
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x194) = 0;
  }
  return 1;
}

