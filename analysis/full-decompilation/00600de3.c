
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined1 FUN_00600de3(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
  iVar2 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (**(code **)(iVar2 + 0x18))(uVar3,unaff_EBP + -0x30);
  (**(code **)(*extraout_ECX + 0x1c))(uVar3,unaff_EBP + -0x24);
  uVar1 = extraout_ECX[2];
  if (uVar1 < 0xe) {
    if (uVar1 == 0xd) {
LAB_00600e85:
      if (*(int *)(unaff_EBP + 0x18) == 0) {
        uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
        uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
LAB_00600f62:
        pcVar5 = s__u__u__4u_006d90a8;
        goto LAB_0060106c;
      }
      iVar2 = *(int *)(unaff_EBP + 0x18) + -1;
      if (iVar2 != 0) goto LAB_0060100b;
LAB_00600e93:
      pcVar5 = s__u__4u_006d90f4;
      uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
    }
    else {
      switch(uVar1) {
      default:
        goto LAB_00600f16;
      case 2:
      case 5:
      case 6:
        goto LAB_00600e85;
      case 3:
      case 4:
      case 9:
      case 10:
      case 0xb:
LAB_00600f6c:
        if (*(int *)(unaff_EBP + 0x18) == 0) {
          uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
          uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
          pcVar5 = s__u__u__4u_006d9094;
          goto LAB_0060106c;
        }
        iVar2 = *(int *)(unaff_EBP + 0x18) + -1;
        if (iVar2 != 0) goto LAB_0060100b;
        pcVar5 = s__u__4u_006d90a0;
        uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
        break;
      case 7:
      case 8:
        goto LAB_00601001;
      }
    }
LAB_00600fe2:
    FUN_005d5156(unaff_EBP + -0x18,pcVar5,uVar3,uVar7);
  }
  else {
    if (uVar1 != 0xe) {
      uVar7 = uVar3;
      if (uVar1 == 0xf) {
        iVar2 = *(int *)(unaff_EBP + 0x18);
        if (iVar2 == 0) {
          uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
          uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
          pcVar5 = s__4u__u__u_006d906c;
          goto LAB_0060106c;
        }
        if (iVar2 == 1) {
          pcVar5 = s__4u__u_006d9078;
          uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
          goto LAB_00600fe2;
        }
        if (iVar2 == 2) {
          uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
          uVar3 = *(undefined4 *)(unaff_EBP + -0x30);
LAB_00600fcc:
          uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
          pcVar5 = s__4u__s__u_006d9080;
          goto LAB_0060106c;
        }
        if (iVar2 == 3) {
          uVar7 = *(undefined4 *)(unaff_EBP + -0x30);
LAB_00600faf:
          pcVar5 = s__4u__s_006d908c;
          uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
          goto LAB_00600fe2;
        }
        if (iVar2 == 4) {
          uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
          uVar3 = *(undefined4 *)(unaff_EBP + -0x24);
          goto LAB_00600fcc;
        }
        if (iVar2 == 5) {
          uVar7 = *(undefined4 *)(unaff_EBP + -0x24);
          goto LAB_00600faf;
        }
LAB_00601017:
        uVar4 = 0;
        goto LAB_0060108b;
      }
      if (uVar1 == 0x10) goto LAB_00600f6c;
      if (0x10 < uVar1) {
        if (uVar1 < 0x13) {
          iVar2 = *(int *)(unaff_EBP + 0x18);
          if (iVar2 == 0) {
            uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
            uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
            pcVar5 = s__4u__u__u_006d90cc;
            goto LAB_0060106c;
          }
          if (iVar2 == 1) {
            pcVar5 = s__4u__u_006d90d8;
            uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
            goto LAB_00600fe2;
          }
          if (iVar2 != 2) {
            if (iVar2 == 3) {
              uVar7 = *(undefined4 *)(unaff_EBP + -0x30);
            }
            else {
              if (iVar2 == 4) {
                uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
                uVar3 = *(undefined4 *)(unaff_EBP + -0x24);
                goto LAB_00600eea;
              }
              if (iVar2 != 5) goto LAB_00601017;
              uVar7 = *(undefined4 *)(unaff_EBP + -0x24);
            }
            pcVar5 = s__4u__s_006d90ec;
            uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
            goto LAB_00600fe2;
          }
          uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
          uVar3 = *(undefined4 *)(unaff_EBP + -0x30);
LAB_00600eea:
          uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
          pcVar5 = s__4u__s__u_006d90e0;
          goto LAB_0060106c;
        }
        if (uVar1 == 0x13) goto LAB_00600e85;
      }
LAB_00600f16:
      iVar2 = *(int *)(unaff_EBP + 0x18);
      if (iVar2 == 0) {
        uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
        uVar6 = uVar3;
        uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
        goto LAB_00600f62;
      }
      if (iVar2 == 1) goto LAB_00600e93;
      if (iVar2 == 2) {
        uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
        uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
        uVar6 = *(undefined4 *)(unaff_EBP + -0x30);
        pcVar5 = s__s__u___4u_006d90b4;
        goto LAB_0060106c;
      }
      if (iVar2 != 3) {
        iVar2 = iVar2 + -4;
        if (iVar2 == 0) {
          uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
          uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
          uVar6 = *(undefined4 *)(unaff_EBP + -0x24);
          pcVar5 = s__s___u___4u_006d90c0;
          goto LAB_0060106c;
        }
        goto LAB_00601014;
      }
LAB_00601038:
      pcVar5 = s__s__4u_006d9050;
      uVar3 = *(undefined4 *)(unaff_EBP + -0x30);
      uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
      goto LAB_00600fe2;
    }
LAB_00601001:
    if (*(int *)(unaff_EBP + 0x18) == 0) {
      uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
      uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
      pcVar5 = s__u__u__4u_006d9030;
      goto LAB_0060106c;
    }
    iVar2 = *(int *)(unaff_EBP + 0x18) + -1;
    if (iVar2 == 0) {
      uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
      pcVar5 = s__u__4u_006d903c;
      goto LAB_00600fe2;
    }
LAB_0060100b:
    if (iVar2 == 1) {
      uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
      uVar3 = *(undefined4 *)(unaff_EBP + -0x30);
      uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
      pcVar5 = s__u__s___4u_006d9044;
    }
    else {
      if (iVar2 == 2) goto LAB_00601038;
      iVar2 = iVar2 + -3;
      if (iVar2 != 0) {
LAB_00601014:
        if (iVar2 == 1) {
          pcVar5 = s__s___4u_006d9064;
          uVar3 = *(undefined4 *)(unaff_EBP + -0x24);
          uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
          goto LAB_00600fe2;
        }
        goto LAB_00601017;
      }
      uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
      uVar3 = *(undefined4 *)(unaff_EBP + -0x24);
      uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
      pcVar5 = s__u__s____4u_006d9058;
    }
LAB_0060106c:
    FUN_005d5156(unaff_EBP + -0x18,pcVar5,uVar6,uVar3,uVar7);
  }
  uVar3 = FUN_004096c2();
  FUN_005d49b7(uVar3);
  uVar4 = 1;
LAB_0060108b:
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

