
void __thiscall FUN_004346fc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_1c [16];
  int local_c;
  int local_8;
  
  local_c = 0;
  iVar4 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1;
  if (0 < iVar4) {
    local_8 = 0x24;
    do {
      if ((local_8 < 0x24) ||
         ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= local_c)) {
        iVar2 = 0;
      }
      else {
        iVar2 = local_8 + *(int *)(param_1 + 0x130);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_00407498((int)*(short *)(iVar2 + 0x10));
      }
      if ((iVar2 != 0) &&
         (((*(byte *)(*(int *)(iVar2 + 0x118) + 0xca) & 1) != 0 ||
          (*(char *)(DAT_006e486c + 0x5c) != '\0')))) {
        param_2 = 1;
        break;
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x24;
    } while (local_c < iVar4);
  }
  if ((*(int *)(param_1 + 0x15c) != param_2) &&
     (iVar4 = FUN_004a696f(), *(int *)(param_1 + 0x110) <= iVar4)) {
    FUN_00438fc0(local_1c,3);
    FUN_004a6af5(local_1c);
    *(int *)(param_1 + 0x15c) = param_2;
  }
  uVar1 = DAT_006e5490;
  if (*(int *)(param_1 + 0x15c) == 1) {
    *(undefined4 *)(param_1 + 0x154) = 0x7fffffff;
    *(undefined4 *)(param_1 + 0x158) = uVar1;
  }
  if (param_3 == 0) {
    iVar4 = 0;
    iVar2 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1;
    if (0 < iVar2) {
      param_3 = 0x24;
      do {
        if ((param_3 < 0x24) ||
           ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= iVar4)) {
          iVar3 = 0;
        }
        else {
          iVar3 = param_3 + *(int *)(param_1 + 0x130);
        }
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_00407498((int)*(short *)(iVar3 + 0x10));
        }
        if (iVar3 != 0) {
          FUN_004346fc(param_2,0);
        }
        param_3 = param_3 + 0x24;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return;
}

