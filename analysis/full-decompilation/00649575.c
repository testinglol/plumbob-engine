
undefined4 FUN_00649575(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 *puVar6;
  undefined4 local_10;
  undefined4 local_c;
  
  bVar1 = false;
  if (param_1 == 2) {
    puVar6 = &DAT_00703e4c;
    pcVar5 = DAT_00703e4c;
LAB_006495fb:
    bVar1 = true;
    FUN_0063d88b(1);
    iVar2 = param_1;
  }
  else {
    if (((param_1 != 4) && (param_1 != 8)) && (param_1 != 0xb)) {
      if (param_1 == 0xf) {
        puVar6 = &DAT_00703e58;
        pcVar5 = DAT_00703e58;
      }
      else if (param_1 == 0x15) {
        puVar6 = &DAT_00703e50;
        pcVar5 = DAT_00703e50;
      }
      else {
        if (param_1 != 0x16) {
          return 0xffffffff;
        }
        puVar6 = &DAT_00703e54;
        pcVar5 = DAT_00703e54;
      }
      goto LAB_006495fb;
    }
    iVar2 = FUN_0063e1d3();
    iVar4 = FUN_006496f7(param_1,*(undefined4 *)(iVar2 + 0x50));
    puVar6 = (undefined4 *)(iVar4 + 8);
    pcVar5 = (code *)*puVar6;
  }
  if (pcVar5 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_0063d8ec(1);
    return 0;
  }
  if (pcVar5 == (code *)0x0) {
    if (bVar1) {
      FUN_0063d8ec(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
    local_c = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar2 + 0x54) = 0;
    if (param_1 == 8) {
      local_10 = *(undefined4 *)(iVar2 + 0x58);
      *(undefined4 *)(iVar2 + 0x58) = 0x8c;
      goto LAB_0064966f;
    }
  }
  else {
LAB_0064966f:
    if (param_1 == 8) {
      if (DAT_006ddd10 < DAT_006ddd14 + DAT_006ddd10) {
        iVar3 = DAT_006ddd10 * 0xc;
        iVar4 = DAT_006ddd10;
        do {
          iVar3 = iVar3 + 0xc;
          *(undefined4 *)(*(int *)(iVar2 + 0x50) + -4 + iVar3) = 0;
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_006ddd14 + DAT_006ddd10);
      }
      goto LAB_006496ad;
    }
  }
  *puVar6 = 0;
LAB_006496ad:
  if (bVar1) {
    FUN_0063d8ec(1);
  }
  if (param_1 == 8) {
    (*pcVar5)(8,*(undefined4 *)(iVar2 + 0x58));
  }
  else {
    (*pcVar5)(param_1);
    if ((param_1 != 0xb) && (param_1 != 4)) {
      return 0;
    }
  }
  *(undefined4 *)(iVar2 + 0x54) = local_c;
  if (param_1 == 8) {
    *(undefined4 *)(iVar2 + 0x58) = local_10;
  }
  return 0;
}

