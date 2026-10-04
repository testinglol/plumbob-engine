
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_005072f5(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *extraout_ECX;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  iVar4 = *(int *)(iVar2 + 0xa0);
  iVar8 = 4;
  extraout_ECX[0x11a] = iVar4;
  extraout_ECX[0x11b] = *(int *)(iVar2 + 0xa4);
  iVar5 = 8;
  if (iVar4 == 0) {
    switch(*(undefined4 *)(iVar2 + 0xa8)) {
    case 0:
      iVar4 = iVar5;
      break;
    case 1:
      iVar4 = 0x20;
      break;
    case 2:
      iVar4 = 2;
      break;
    case 3:
      iVar4 = 0x80;
      break;
    case 4:
      iVar4 = 1;
      break;
    case 5:
      iVar4 = iVar8;
      break;
    case 6:
      iVar4 = 0x10;
      break;
    case 7:
      iVar4 = 0x40;
      break;
    default:
      iVar4 = 0;
    }
    extraout_ECX[0x11c] = iVar4;
    switch(*(undefined4 *)(iVar2 + 0xac)) {
    case 0:
      goto code_r0x005075db;
    case 1:
code_r0x00507567:
      iVar5 = 2;
      break;
    case 2:
code_r0x00507573:
      iVar5 = 0x20;
      break;
    case 3:
code_r0x0050756f:
      break;
    case 4:
code_r0x0050756b:
      iVar5 = iVar8;
      break;
    case 5:
      goto code_r0x00507505;
    case 6:
      goto code_r0x0050750c;
    case 7:
code_r0x00507577:
      iVar5 = 0x40;
      break;
    default:
LAB_005075e0:
      iVar5 = 0;
    }
  }
  else if (iVar4 == 1) {
    switch(*(undefined4 *)(iVar2 + 0xb0)) {
    case 0:
      iVar4 = 1;
      break;
    case 1:
      iVar4 = 2;
      break;
    case 2:
      iVar4 = 0x20;
      break;
    case 3:
      iVar4 = iVar5;
      break;
    case 4:
      iVar4 = iVar8;
      break;
    case 5:
      iVar4 = 0x10;
      break;
    case 6:
      iVar4 = 0x80;
      break;
    case 7:
      iVar4 = 0x40;
      break;
    default:
      iVar4 = 0;
    }
    extraout_ECX[0x11c] = iVar4;
    switch(*(undefined4 *)(iVar2 + 0xb4)) {
    case 0:
      goto code_r0x005075db;
    case 1:
      goto code_r0x00507567;
    case 2:
      goto code_r0x0050756b;
    case 3:
      goto code_r0x0050756f;
    case 4:
      goto code_r0x00507573;
    case 5:
      goto code_r0x00507577;
    case 6:
      iVar5 = 0x90;
      break;
    case 7:
      iVar5 = 0xff;
      break;
    default:
      goto LAB_005075e0;
    }
  }
  else {
    if (iVar4 != 2) {
      if (iVar4 != 3) {
        if (iVar4 != 4) {
          if (iVar4 != 5) {
            if (iVar4 != 6) goto LAB_005075e8;
            switch(*(undefined4 *)(iVar2 + 0xd8)) {
            case 0:
              iVar4 = 1;
              break;
            case 1:
              iVar4 = 2;
              break;
            case 2:
              iVar4 = iVar8;
              break;
            case 3:
              iVar4 = iVar5;
              break;
            case 4:
              iVar4 = 0x10;
              break;
            case 5:
              iVar4 = 0x20;
              break;
            case 6:
              iVar4 = 0x40;
              break;
            case 7:
              iVar4 = 0x80;
              break;
            default:
              iVar4 = 0;
            }
            extraout_ECX[0x11c] = iVar4;
            switch(*(undefined4 *)(iVar2 + 0xdc)) {
            case 0:
              goto code_r0x005075db;
            case 1:
              goto code_r0x00507567;
            case 2:
              goto code_r0x00507573;
            case 3:
              goto code_r0x0050756f;
            case 4:
              goto code_r0x0050756b;
            case 5:
              goto code_r0x00507505;
            case 6:
              goto code_r0x0050750c;
            case 7:
              goto code_r0x00507577;
            default:
              goto LAB_005075e0;
            }
          }
          switch(*(undefined4 *)(iVar2 + 0xd0)) {
          case 0:
            iVar4 = 1;
            break;
          case 1:
            iVar4 = 2;
            break;
          case 2:
            iVar4 = iVar8;
            break;
          case 3:
            iVar4 = iVar5;
            break;
          case 4:
            iVar4 = 0x10;
            break;
          case 5:
            iVar4 = 0x20;
            break;
          case 6:
            iVar4 = 0x40;
            break;
          case 7:
            iVar4 = 0x80;
            break;
          default:
            iVar4 = 0;
          }
          extraout_ECX[0x11c] = iVar4;
          switch(*(undefined4 *)(iVar2 + 0xd4)) {
          case 0:
            goto code_r0x005075db;
          case 1:
            goto code_r0x00507567;
          case 2:
            goto code_r0x00507573;
          case 3:
            goto code_r0x0050756f;
          case 4:
            goto code_r0x0050756b;
          case 5:
            goto code_r0x00507505;
          case 6:
            goto code_r0x0050750c;
          case 7:
            goto code_r0x00507577;
          default:
            goto LAB_005075e0;
          }
        }
        switch(*(undefined4 *)(iVar2 + 200)) {
        case 0:
          iVar4 = 1;
          break;
        case 1:
          iVar4 = 2;
          break;
        case 2:
          iVar4 = iVar8;
          break;
        case 3:
          iVar4 = iVar5;
          break;
        case 4:
          iVar4 = 0x10;
          break;
        case 5:
          iVar4 = 0x20;
          break;
        case 6:
          iVar4 = 0x40;
          break;
        case 7:
          iVar4 = 0x80;
          break;
        default:
          iVar4 = 0;
        }
        extraout_ECX[0x11c] = iVar4;
        switch(*(undefined4 *)(iVar2 + 0xcc)) {
        case 0:
          goto code_r0x005075db;
        case 1:
          goto code_r0x00507567;
        case 2:
          goto code_r0x00507573;
        case 3:
          goto code_r0x0050756f;
        case 4:
          goto code_r0x0050756b;
        case 5:
          goto code_r0x00507505;
        case 6:
          goto code_r0x0050750c;
        case 7:
          goto code_r0x00507577;
        default:
          goto LAB_005075e0;
        }
      }
      switch(*(undefined4 *)(iVar2 + 0xc0)) {
      case 0:
        iVar4 = 1;
        break;
      case 1:
        iVar4 = 2;
        break;
      case 2:
        iVar4 = iVar8;
        break;
      case 3:
        iVar4 = iVar5;
        break;
      case 4:
        iVar4 = 0x10;
        break;
      case 5:
        iVar4 = 0x20;
        break;
      case 6:
        iVar4 = 0x40;
        break;
      case 7:
        iVar4 = 0x80;
        break;
      default:
        iVar4 = 0;
      }
      extraout_ECX[0x11c] = iVar4;
      switch(*(undefined4 *)(iVar2 + 0xc4)) {
      case 0:
        goto code_r0x005075db;
      case 1:
        goto code_r0x00507567;
      case 2:
        goto code_r0x00507573;
      case 3:
        goto code_r0x0050756f;
      case 4:
        goto code_r0x0050756b;
      case 5:
        goto code_r0x00507505;
      case 6:
        goto code_r0x0050750c;
      case 7:
        goto code_r0x00507577;
      default:
        goto LAB_005075e0;
      }
    }
    switch(*(undefined4 *)(iVar2 + 0xb8)) {
    case 0:
      iVar4 = 1;
      break;
    case 1:
      iVar4 = 2;
      break;
    case 2:
      iVar4 = iVar8;
      break;
    case 3:
      iVar4 = iVar5;
      break;
    case 4:
      iVar4 = 0x10;
      break;
    case 5:
      iVar4 = 0x20;
      break;
    case 6:
      iVar4 = 0x40;
      break;
    case 7:
      iVar4 = 0x80;
      break;
    default:
      iVar4 = 0;
    }
    extraout_ECX[0x11c] = iVar4;
    switch(*(undefined4 *)(iVar2 + 0xbc)) {
    case 0:
code_r0x005075db:
      iVar5 = 1;
      break;
    case 1:
      goto code_r0x00507567;
    case 2:
      goto code_r0x00507573;
    case 3:
      goto code_r0x0050756f;
    case 4:
      goto code_r0x0050756b;
    case 5:
code_r0x00507505:
      iVar5 = 0x10;
      break;
    case 6:
code_r0x0050750c:
      iVar5 = 0x80;
      break;
    case 7:
      goto code_r0x00507577;
    default:
      goto LAB_005075e0;
    }
  }
  extraout_ECX[0x11d] = iVar5;
LAB_005075e8:
  if (((*(uint *)(iVar2 + 0xc) & 0x400) != 0) ||
     (((*(uint *)(iVar2 + 0xc) & 2) != 0 && (iVar2 = FUN_00401f6f(), iVar2 == 1)))) {
    iVar2 = extraout_ECX[0x109];
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    piVar7 = extraout_ECX + 0x108;
    if (iVar2 - extraout_ECX[0x108] >> 2 != 0) {
      do {
        iVar2 = *(int *)(unaff_EBP + -0x1c) * 4;
        if (*(int *)(*piVar7 + iVar2) != 0) {
          if (extraout_ECX[0x11b] == 0) {
LAB_005076f8:
            FUN_004ccecd();
          }
          else {
            iVar4 = extraout_ECX[0x11a];
            if (iVar4 == 0) {
              cVar1 = FUN_004cba76(extraout_ECX[0x11c]);
              goto LAB_005076de;
            }
            if (iVar4 == 1) {
              cVar1 = FUN_004cbaca(extraout_ECX[0x11c],extraout_ECX[0x11d]);
LAB_005076f2:
              if (cVar1 == '\0') goto LAB_005076f8;
            }
            else {
              if (iVar4 == 2) {
                cVar1 = FUN_004cbb5c(extraout_ECX[0x11c]);
LAB_005076de:
                if (cVar1 == '\0') goto LAB_005076f8;
                cVar1 = FUN_004cbaac(extraout_ECX[0x11d]);
                goto LAB_005076f2;
              }
              if (iVar4 == 3) {
                cVar1 = FUN_004cbb7d(extraout_ECX[0x11c]);
                goto LAB_005076de;
              }
              if (iVar4 == 4) {
                cVar1 = FUN_004cbb9e(extraout_ECX[0x11c]);
                goto LAB_005076de;
              }
              if (iVar4 == 5) {
                cVar1 = FUN_004cbbbf(extraout_ECX[0x11c]);
                goto LAB_005076de;
              }
              if (iVar4 == 6) {
                cVar1 = FUN_004cbbe0(extraout_ECX[0x11c]);
                goto LAB_005076de;
              }
            }
          }
          piVar3 = (int *)FUN_00492d2c();
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0x98))();
          }
          *(undefined4 *)(*piVar7 + iVar2) = 0;
        }
        iVar2 = extraout_ECX[0x109];
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      } while (*(uint *)(unaff_EBP + -0x1c) < (uint)(iVar2 - *piVar7 >> 2));
    }
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    iVar4 = FUN_005f65c1();
    *(int *)(unaff_EBP + -0x28) = iVar4;
    iVar2 = extraout_ECX[0x35];
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    uVar6 = *(undefined4 *)(iVar2 + 0x54);
    *(bool *)(unaff_EBP + -0xe) = iVar4 != 0;
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
    FUN_004d26ba(uVar6,unaff_EBP + -0x34,unaff_EBP + -0x30);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    extraout_ECX[0x114] = (extraout_ECX[0x21] - extraout_ECX[0x1f]) + -0xc;
    extraout_ECX[0x110] = -iVar2 + 0x19f;
    extraout_ECX[0x111] = 5;
    extraout_ECX[0x115] = 0x5f;
    extraout_ECX[0x112] = 0x2d;
    extraout_ECX[0x113] = 0x2d;
    extraout_ECX[0x116] = 0x2d;
    extraout_ECX[0x117] = 0x2d;
    extraout_ECX[0x10e] = extraout_ECX[0x21] - extraout_ECX[0x1f];
    extraout_ECX[0x10c] = -iVar2 + 0x18b;
    extraout_ECX[0x10d] = 5;
    extraout_ECX[0x10f] = 0x5f;
    iVar2 = FUN_00500b95();
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    extraout_ECX[0x119] = iVar2;
    FUN_00507e84(iVar2,unaff_EBP + -0x18);
    if (extraout_ECX[0x11b] != 0) {
      iVar5 = FUN_004ce4a9();
      iVar2 = *(int *)(iVar5 + 8);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      iVar4 = *(int *)(iVar5 + 4);
      *(undefined1 *)(extraout_ECX + 0x11e) = 0;
      iVar8 = *(int *)(unaff_EBP + -0x1c);
      *(int *)(unaff_EBP + -0x24) = iVar5;
      iVar2 = iVar2 - iVar4 >> 2;
      *(int *)(unaff_EBP + -0x2c) = iVar2;
      if (0 < iVar2) {
        do {
          *(undefined4 *)(unaff_EBP + -0x14) =
               *(undefined4 *)
                (*(int *)(*(int *)(unaff_EBP + -0x24) + 4) + *(int *)(unaff_EBP + -0x18) * 4);
          iVar2 = extraout_ECX[0x11a];
          if (iVar2 == 0) {
            cVar1 = FUN_004cba94();
            if (cVar1 != '\0') {
              cVar1 = FUN_004cba76(extraout_ECX[0x11c]);
              goto LAB_00507959;
            }
          }
          else if (iVar2 == 1) {
            cVar1 = FUN_004cba94();
            if ((cVar1 != '\0') &&
               (cVar1 = FUN_004cbaca(extraout_ECX[0x11c],extraout_ECX[0x11d]), cVar1 == '\x01')) {
LAB_00507977:
              if (extraout_ECX[0x119] * *(int *)(unaff_EBP + -0x28) <= *(int *)(unaff_EBP + -0x20))
              {
                if (extraout_ECX[0x119] <= iVar8) {
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                  break;
                }
                if ((*(int *)(unaff_EBP + -0x14) != 0) && (cVar1 = FUN_004ccef6(), cVar1 != '\0')) {
                  *(undefined1 *)(extraout_ECX + 0x11e) = 1;
                }
                *(undefined4 *)(extraout_ECX[0x108] + iVar8 * 4) =
                     *(undefined4 *)(unaff_EBP + -0x14);
                *(int *)(unaff_EBP + -0x14) = *extraout_ECX;
                uVar6 = FUN_00492d2c();
                cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x38))(uVar6);
                if (cVar1 == '\0') {
                  iVar2 = *extraout_ECX;
                  uVar6 = FUN_00492d2c();
                  (**(code **)(iVar2 + 0x20))(uVar6);
                }
                iVar8 = *(int *)(unaff_EBP + -0x1c);
                piVar7 = (int *)FUN_00492d2c();
                (**(code **)(*piVar7 + 0x94))();
                iVar8 = iVar8 + 1;
                *(int *)(unaff_EBP + -0x1c) = iVar8;
              }
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
            }
          }
          else if (iVar2 == 2) {
            cVar1 = FUN_004cbc01();
            if (cVar1 != '\0') {
              cVar1 = FUN_004cbb5c(extraout_ECX[0x11c]);
              goto LAB_00507959;
            }
          }
          else if (iVar2 == 3) {
            cVar1 = FUN_004cbc1c();
            if (cVar1 != '\0') {
              cVar1 = FUN_004cbb7d(extraout_ECX[0x11c]);
              goto LAB_00507959;
            }
          }
          else if (iVar2 == 4) {
            cVar1 = FUN_004cbc37();
            if (cVar1 != '\0') {
              cVar1 = FUN_004cbb9e(extraout_ECX[0x11c]);
              goto LAB_00507959;
            }
          }
          else if (iVar2 == 5) {
            cVar1 = FUN_004cbc52();
            if (cVar1 != '\0') {
              cVar1 = FUN_004cbbbf(extraout_ECX[0x11c]);
              goto LAB_00507959;
            }
          }
          else if ((iVar2 == 6) && (cVar1 = FUN_004cbc6d(), cVar1 != '\0')) {
            cVar1 = FUN_004cbbe0(extraout_ECX[0x11c]);
LAB_00507959:
            if ((cVar1 != '\0') && (cVar1 = FUN_004cbaac(extraout_ECX[0x11d]), cVar1 != '\0'))
            goto LAB_00507977;
          }
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x2c));
      }
      for (; iVar8 < extraout_ECX[0x119]; iVar8 = iVar8 + 1) {
        *(undefined4 *)(extraout_ECX[0x108] + iVar8 * 4) = 0;
      }
      iVar2 = extraout_ECX[0x109];
      piVar7 = extraout_ECX + 0x108;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      iVar2 = iVar2 - *piVar7 >> 2;
      *(int *)(unaff_EBP + -0x28) = iVar2;
      FUN_0054821c(iVar2,unaff_EBP + -0xf);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x28),
                           unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x3c) = uVar6;
      iVar2 = extraout_ECX[0x109];
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      iVar4 = *piVar7;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (iVar2 - iVar4 >> 2 != 0) {
        do {
          iVar2 = *(int *)(unaff_EBP + -0x18) * 4;
          if (*(int *)(*piVar7 + iVar2) != 0) {
            *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x40) + iVar2;
            uVar6 = FUN_00492d2c();
            **(undefined4 **)(unaff_EBP + -0x28) = uVar6;
          }
          iVar2 = extraout_ECX[0x109];
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        } while (*(uint *)(unaff_EBP + -0x18) < (uint)(iVar2 - *piVar7 >> 2));
      }
      FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x40),extraout_ECX[0x119]);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
    }
    iVar2 = *(int *)(unaff_EBP + 8);
    (**(code **)(*extraout_ECX + 0x168))();
    *(undefined4 *)(unaff_EBP + 8) = 8;
    do {
      FUN_005e46f0(0);
      piVar7 = (int *)(unaff_EBP + 8);
      *piVar7 = *piVar7 + -1;
    } while (*piVar7 != 0);
    iVar4 = extraout_ECX[0x11a];
    iVar8 = -1;
    if (iVar4 == 0) {
      iVar8 = *(int *)(iVar2 + 0xac);
    }
    else if (iVar4 == 1) {
      iVar8 = *(int *)(iVar2 + 0xb4);
    }
    else if (iVar4 == 2) {
      iVar8 = *(int *)(iVar2 + 0xbc);
    }
    else if (iVar4 == 3) {
      iVar8 = *(int *)(iVar2 + 0xc4);
    }
    else if (iVar4 == 4) {
      iVar8 = *(int *)(iVar2 + 0xcc);
    }
    else if (iVar4 == 5) {
      iVar8 = *(int *)(iVar2 + 0xd4);
    }
    else if (iVar4 == 6) {
      iVar8 = *(int *)(iVar2 + 0xdc);
    }
    if (((extraout_ECX[0x11b] != 0) && (-1 < iVar8)) && (iVar8 < 8)) {
      FUN_005e46f0(1);
    }
    FUN_005067d2(*(undefined4 *)(iVar2 + 0xa0));
    if (*(char *)(unaff_EBP + -0xe) == '\0') {
      (**(code **)(*(int *)extraout_ECX[0x39] + 0x98))();
    }
    else {
      piVar7 = (int *)extraout_ECX[0x39];
      if ((char)piVar7[0x5a] != '\x01') {
        *(undefined1 *)(piVar7 + 0x5a) = 1;
        (**(code **)(*piVar7 + 0x168))();
      }
      (**(code **)(*(int *)extraout_ECX[0x39] + 0x94))();
    }
    if (*(char *)(unaff_EBP + -0xd) == '\0') {
      (**(code **)(*(int *)extraout_ECX[0x3a] + 0x98))();
    }
    else {
      piVar7 = (int *)extraout_ECX[0x3a];
      if ((char)piVar7[0x5a] != '\x01') {
        *(undefined1 *)(piVar7 + 0x5a) = 1;
        (**(code **)(*piVar7 + 0x168))();
      }
      (**(code **)(*(int *)extraout_ECX[0x3a] + 0x94))();
    }
  }
  if ((char)extraout_ECX[0x11e] != '\0') {
    iVar2 = FUN_005e74ca(3);
    if (extraout_ECX[0x11f] != iVar2) {
      extraout_ECX[0x11f] = extraout_ECX[0x1a];
      FUN_005dde6d(iVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

