
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined1 FUN_004965e8(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char cVar8;
  undefined4 uVar9;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x12) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  pcVar4 = *(char **)(unaff_EBP + 8);
  pcVar5 = *(char **)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  cVar8 = *pcVar4;
  if ((cVar8 == *pcVar5) || (pcVar4[1] == pcVar5[1])) {
    pcVar6 = *(char **)(unaff_EBP + 0x10);
    uVar12 = *(undefined4 *)(unaff_EBP + 0x14);
    *pcVar6 = cVar8;
    pcVar6[1] = pcVar4[1];
    uVar11 = 0;
    pcVar6[2] = pcVar4[2];
    uVar9 = FUN_00494906(pcVar4,pcVar5);
    uVar10 = FUN_0049651f(pcVar4,pcVar5,uVar9,uVar11,uVar12);
    goto LAB_004967e0;
  }
  pcVar6 = *(char **)(unaff_EBP + 0x10);
  *pcVar6 = cVar8;
  pcVar6[1] = pcVar4[1];
  pcVar6[2] = pcVar4[2];
  cVar8 = *pcVar5;
  *(char *)(unaff_EBP + -0x13) = pcVar5[1];
  cVar1 = pcVar5[2];
  *(char *)(unaff_EBP + -0x14) = cVar8;
  *(char *)(unaff_EBP + -0x12) = cVar1;
  pcVar7 = *(char **)(unaff_EBP + 0x14);
  *pcVar7 = cVar8;
  pcVar7[1] = pcVar5[1];
  pcVar7[2] = pcVar5[2];
  cVar8 = *pcVar5;
  cVar1 = pcVar5[1];
  cVar2 = pcVar5[2];
  cVar3 = *pcVar4;
  *(char *)(unaff_EBP + -0x10) = cVar8;
  *(char *)(unaff_EBP + -0xf) = cVar1;
  *(char *)(unaff_EBP + -0xe) = cVar2;
  if (cVar3 < cVar8) {
    if (cVar1 <= pcVar4[1]) {
      uVar12 = 3;
      goto LAB_0049667b;
    }
    uVar12 = 1;
LAB_00496694:
    *(char *)(unaff_EBP + -0x14) = *pcVar6;
    *(char *)(unaff_EBP + -0xf) = pcVar6[1];
  }
  else {
    if (cVar1 <= pcVar4[1]) {
      uVar12 = 0;
      goto LAB_00496694;
    }
    uVar12 = 2;
LAB_0049667b:
    *(char *)(unaff_EBP + -0x13) = pcVar6[1];
    *(char *)(unaff_EBP + -0x10) = *pcVar6;
  }
  cVar8 = FUN_0049651f(pcVar6,unaff_EBP + -0x14,uVar12,0,unaff_EBP + -0x14);
  if (cVar8 != '\0') {
    switch(uVar12) {
    case 0:
      uVar12 = 2;
      break;
    case 1:
      uVar12 = 3;
      break;
    case 2:
      uVar12 = 1;
      break;
    case 3:
      uVar12 = 0;
    }
    uVar9 = *(undefined4 *)(unaff_EBP + 0x14);
    FUN_004949f0(unaff_EBP + -0x14,uVar9,uVar12);
    cVar8 = FUN_0049651f(unaff_EBP + -0x14,uVar9,uVar12,0,uVar9);
    if (cVar8 != '\0') {
      switch(uVar12) {
      case 0:
        uVar12 = 2;
        break;
      case 1:
        uVar12 = 3;
        break;
      case 2:
        uVar12 = 1;
        break;
      case 3:
        uVar12 = 0;
      }
      FUN_004949f0(uVar9,unaff_EBP + -0x10,uVar12);
      cVar8 = FUN_0049651f(uVar9,unaff_EBP + -0x10,uVar12,0,unaff_EBP + -0x10);
      if (cVar8 != '\0') {
        switch(uVar12) {
        case 0:
          uVar12 = 2;
          break;
        case 1:
          uVar12 = 3;
          break;
        case 2:
          uVar12 = 1;
          break;
        case 3:
          uVar12 = 0;
        }
        FUN_004949f0(unaff_EBP + -0x10,pcVar6,uVar12);
        cVar8 = FUN_0049651f(unaff_EBP + -0x10,pcVar6,uVar12,0,pcVar6);
        uVar10 = cVar8 != '\0';
        goto LAB_004967e0;
      }
    }
  }
  uVar10 = 0;
LAB_004967e0:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar10;
}

