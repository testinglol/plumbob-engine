
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 * FUN_00504da4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  undefined4 *puVar5;
  int iVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x108] = 0;
  extraout_ECX[0x109] = 0;
  extraout_ECX[0x10a] = 0;
  extraout_ECX[0x110] = 0;
  extraout_ECX[0x111] = 0;
  extraout_ECX[0x112] = 0;
  extraout_ECX[0x113] = 0;
  extraout_ECX[0x114] = 0;
  extraout_ECX[0x115] = 0;
  extraout_ECX[0x116] = 0;
  extraout_ECX[0x117] = 0;
  extraout_ECX[0x118] = 0;
  extraout_ECX[0x35] = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_0066a690;
  puVar3 = extraout_ECX + 0x39;
  iVar6 = 2;
  do {
    puVar3[-2] = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  puVar3 = extraout_ECX + 0x3b;
  for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  extraout_ECX[0x73] = 0;
  FUN_0054821c(8,unaff_EBP + -0xd);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar4 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x24),8,unaff_EBP + -0x14,
                       *(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00501a1a(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0048c4c9();
  puVar3 = extraout_ECX + 0xdc;
  puVar5 = extraout_ECX + 0xd4;
  iVar6 = 8;
  do {
    puVar5[-0x60] = 0;
    *puVar5 = 0;
    puVar5[-0x50] = 0;
    puVar5[-0x48] = 0;
    puVar5[-0x40] = 0;
    puVar5[-0x38] = 0;
    puVar5[-0x30] = 0;
    puVar5[0x2c] = 0;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar1 = puVar3 + 3;
    puVar3[2] = 0;
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 4;
    iVar6 = iVar6 + -1;
    *puVar1 = 0;
  } while (iVar6 != 0);
  extraout_ECX[0x36] = *(undefined4 *)(unaff_EBP + 0xc);
  iVar6 = *(int *)(unaff_EBP + 8);
  extraout_ECX[0xfe] = 0;
  extraout_ECX[0xff] = 0;
  extraout_ECX[0xfc] = 0;
  extraout_ECX[0xfd] = 0;
  extraout_ECX[0x10b] = 0;
  iVar2 = *(int *)(iVar6 + 0xa0);
  extraout_ECX[0x11a] = iVar2;
  uVar4 = 1;
  if (iVar2 != 0) {
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        if (iVar2 != 3) {
          if (iVar2 != 4) {
            if (iVar2 != 5) {
              if (iVar2 != 6) goto LAB_00504fc9;
              switch(*(undefined4 *)(iVar6 + 0xd8)) {
              case 0:
                goto code_r0x00504f8f;
              case 1:
                goto code_r0x00504f79;
              case 2:
                goto code_r0x00504f9b;
              case 3:
                goto code_r0x00504fbd;
              case 4:
                goto code_r0x00504f97;
              case 5:
                goto code_r0x00504f9f;
              case 6:
                goto code_r0x00504f93;
              case 7:
                goto code_r0x00504fa4;
              default:
                goto LAB_00504fc1;
              }
            }
            switch(*(undefined4 *)(iVar6 + 0xd0)) {
            case 0:
              goto code_r0x00504f8f;
            case 1:
              goto code_r0x00504f79;
            case 2:
              goto code_r0x00504f9b;
            case 3:
              goto code_r0x00504fbd;
            case 4:
              goto code_r0x00504f97;
            case 5:
              goto code_r0x00504f9f;
            case 6:
              goto code_r0x00504f93;
            case 7:
              goto code_r0x00504fa4;
            default:
              goto LAB_00504fc1;
            }
          }
          switch(*(undefined4 *)(iVar6 + 200)) {
          case 0:
            goto code_r0x00504f8f;
          case 1:
            goto code_r0x00504f79;
          case 2:
            goto code_r0x00504f9b;
          case 3:
            goto code_r0x00504fbd;
          case 4:
            goto code_r0x00504f97;
          case 5:
            goto code_r0x00504f9f;
          case 6:
            goto code_r0x00504f93;
          case 7:
            goto code_r0x00504fa4;
          default:
            goto LAB_00504fc1;
          }
        }
        switch(*(undefined4 *)(iVar6 + 0xc0)) {
        case 0:
          goto code_r0x00504f8f;
        case 1:
          goto code_r0x00504f79;
        case 2:
          goto code_r0x00504f9b;
        case 3:
          goto code_r0x00504fbd;
        case 4:
          goto code_r0x00504f97;
        case 5:
          goto code_r0x00504f9f;
        case 6:
          goto code_r0x00504f93;
        case 7:
          goto code_r0x00504fa4;
        default:
          goto LAB_00504fc1;
        }
      }
      switch(*(undefined4 *)(iVar6 + 0xb8)) {
      case 0:
        goto code_r0x00504f8f;
      case 1:
        goto code_r0x00504f79;
      case 2:
        goto code_r0x00504f9b;
      case 3:
        goto code_r0x00504fbd;
      case 4:
        goto code_r0x00504f97;
      case 5:
        goto code_r0x00504f9f;
      case 6:
        goto code_r0x00504f93;
      case 7:
        goto code_r0x00504fa4;
      default:
        goto LAB_00504fc1;
      }
    }
    switch(*(undefined4 *)(iVar6 + 0xb0)) {
    case 0:
      goto code_r0x00504f8f;
    case 1:
      goto code_r0x00504f79;
    case 2:
      goto code_r0x00504f9f;
    case 3:
      goto code_r0x00504fbd;
    case 4:
      goto code_r0x00504f9b;
    case 5:
      goto code_r0x00504f97;
    case 6:
      goto code_r0x00504fa4;
    case 7:
      goto code_r0x00504f93;
    default:
      goto LAB_00504fc1;
    }
  }
  switch(*(undefined4 *)(iVar6 + 0xa8)) {
  case 0:
code_r0x00504fbd:
    uVar4 = 8;
    break;
  case 1:
code_r0x00504f9f:
    uVar4 = 0x20;
    break;
  case 2:
code_r0x00504f79:
    uVar4 = 2;
    break;
  case 3:
code_r0x00504fa4:
    uVar4 = 0x80;
    break;
  case 4:
code_r0x00504f8f:
    break;
  case 5:
code_r0x00504f9b:
    uVar4 = 4;
    break;
  case 6:
code_r0x00504f97:
    uVar4 = 0x10;
    break;
  case 7:
code_r0x00504f93:
    uVar4 = 0x40;
    break;
  default:
LAB_00504fc1:
    uVar4 = 0;
  }
  extraout_ECX[0x11c] = uVar4;
LAB_00504fc9:
  *(undefined1 *)(extraout_ECX + 0x11e) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x11a] = 1;
  extraout_ECX[0x11f] = 0;
  extraout_ECX[0x11b] = 0;
  extraout_ECX[0x11c] = 0;
  extraout_ECX[0x11d] = 0;
  return extraout_ECX;
}

