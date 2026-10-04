
void __thiscall FUN_005f2c6c(int param_1,int param_2,char param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  
  local_c = *(int *)(param_1 + 0xd8);
  local_8 = *(int *)(*(int *)(param_1 + 0xf0) + local_c * 4);
  if (param_4 != '\0') {
    param_2 = FUN_005f2b22(*(undefined4 *)(param_1 + 0xd4),param_2);
  }
  if (param_3 == '\0') {
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    goto LAB_005f2d77;
  }
  iVar3 = *(int *)(param_1 + 0x144);
  iVar5 = *(int *)(param_1 + 0x140);
  if (iVar5 < iVar3) {
    iVar2 = *(int *)(param_1 + 0xd4);
    if (iVar2 < iVar5) {
      *(int *)(param_1 + 0x140) = iVar2;
    }
    else if ((iVar2 == iVar5) && (0 < param_2)) {
      if (iVar3 < iVar5 + param_2) {
        *(int *)(param_1 + 0x140) = iVar3;
        *(int *)(param_1 + 0x144) = iVar5 + param_2;
      }
      else {
        *(int *)(param_1 + 0x140) = iVar5 + param_2;
      }
    }
    iVar3 = *(int *)(param_1 + 0x144);
    if (iVar3 < iVar2) {
      *(int *)(param_1 + 0x144) = iVar2;
      goto LAB_005f2d77;
    }
    if (iVar2 != iVar3) goto LAB_005f2d77;
    if (-1 < param_2) {
      if (param_2 < 1) goto LAB_005f2d77;
      goto LAB_005f2d27;
    }
    iVar3 = param_2 + iVar3;
    iVar5 = *(int *)(param_1 + 0x140);
    if (iVar5 <= iVar3) {
      *(int *)(param_1 + 0x144) = iVar3;
      goto LAB_005f2d77;
    }
LAB_005f2d47:
    *(int *)(param_1 + 0x140) = iVar3;
  }
  else {
    if (param_2 < 1) {
      if (-1 < param_2) {
        *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0xd4);
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0xd4);
        goto LAB_005f2d77;
      }
      iVar5 = *(int *)(param_1 + 0xd4);
      iVar3 = param_2 + iVar5;
      goto LAB_005f2d47;
    }
    iVar3 = *(int *)(param_1 + 0xd4);
    *(int *)(param_1 + 0x140) = iVar3;
LAB_005f2d27:
    iVar5 = iVar3 + param_2;
  }
  *(int *)(param_1 + 0x144) = iVar5;
LAB_005f2d77:
  piVar1 = (int *)(param_1 + 0xd4);
  iVar3 = FUN_005f2e7f(piVar1,&param_2);
  iVar5 = local_c;
  do {
    if (iVar3 == 0) {
LAB_005f2dc3:
      if (local_8 != 0) {
        *(int *)(param_1 + 0xd8) = iVar5;
        puVar4 = (undefined4 *)FUN_005f2e1e(local_10,*piVar1);
        *(undefined4 *)(param_1 + 0xdc) = *puVar4;
        *(undefined4 *)(param_1 + 0xe0) = puVar4[1];
      }
      if (param_3 != '\0') {
        iVar3 = *piVar1;
        if (iVar3 < *(int *)(param_1 + 0x140)) {
          *(int *)(param_1 + 0x140) = iVar3;
        }
        if (*(int *)(param_1 + 0x144) < iVar3) {
          *(int *)(param_1 + 0x144) = iVar3;
        }
      }
      FUN_005f37cd();
      return;
    }
    iVar5 = iVar5 + iVar3;
    if (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2 <= iVar5) {
      iVar5 = iVar5 + -1;
      goto LAB_005f2dc3;
    }
    local_8 = *(int *)(*(int *)(param_1 + 0xf0) + iVar5 * 4);
    iVar3 = FUN_005f2e7f(piVar1,&param_2);
  } while( true );
}

