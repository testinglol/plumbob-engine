
undefined1 FUN_005a5631(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  size_t sVar6;
  int iVar7;
  void *pvVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006f7690);
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  FUN_0046f824(unaff_EBP + -0x260,0,0x104);
  *(undefined ***)(unaff_EBP + -0x26c) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x150,0,0x104);
  *(undefined ***)(unaff_EBP + -0x15c) = &PTR_FUN_006664e8;
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *piVar1 = 0;
  iVar7 = *(int *)(DAT_006f2a08 + 0x8c);
  *(int *)(unaff_EBP + -0x20) = iVar7;
  iVar2 = DAT_006e486c;
  if (iVar7 != 0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(int *)(unaff_EBP + -0x28) = (int)*(char *)(iVar2 + 100);
    *(int *)(unaff_EBP + -0x14) = unaff_EBP + -0x28;
    do {
      cVar3 = FUN_005a3ddd(*(undefined4 *)(unaff_EBP + 8),**(undefined4 **)(unaff_EBP + -0x14),
                           unaff_EBP + -0x26c,unaff_EBP + -0x1c);
      if (cVar3 != '\0') {
        uVar5 = FUN_0041532c(0x10,*(undefined4 *)(unaff_EBP + -0x268),unaff_EBP + -0x15c);
        FUN_004ee9ce(uVar5);
        FUN_004b8915(unaff_EBP + -0x4c,*(undefined4 *)(unaff_EBP + -0x158));
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        sVar6 = _strlen((char *)(unaff_EBP + -0x4c));
        if (sVar6 != 0) {
          do {
            iVar7 = *(int *)(unaff_EBP + 0xc);
            uVar4 = FUN_0063813a((int)*(char *)(unaff_EBP + -0x4c + iVar7));
            *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
            *(undefined1 *)(unaff_EBP + -0x4c + iVar7) = uVar4;
            sVar6 = _strlen((char *)(unaff_EBP + -0x4c));
          } while (*(uint *)(unaff_EBP + 0xc) < sVar6);
        }
        iVar7 = _strcmp((char *)(unaff_EBP + -0x4c),(char *)&PTR_DAT_006ccc14);
        if (iVar7 == 0) {
          if (*(int *)(unaff_EBP + -0x1c) == 0) {
            iVar7 = FUN_004dedc6(unaff_EBP + -0x15c,*(undefined4 *)(unaff_EBP + 0x10));
            goto LAB_005a57f3;
          }
          pvVar8 = operator_new(100);
          *(void **)(unaff_EBP + 0xc) = pvVar8;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar8 == (void *)0x0) {
            iVar7 = 0;
          }
          else {
            iVar7 = FUN_005dfb13();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *piVar1 = iVar7;
          if (iVar7 == 0) {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          else {
            cVar3 = FUN_005e27ee(*(undefined4 *)(unaff_EBP + -0x158));
            *(char *)(unaff_EBP + -0xd) = cVar3;
            if (cVar3 == '\0') {
              if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
                (*(code *)**(undefined4 **)*piVar1)(1);
              }
              uVar5 = *(undefined4 *)(unaff_EBP + 0x10);
              *piVar1 = 0;
              iVar7 = FUN_004dedc6(unaff_EBP + -0x15c,uVar5);
              *piVar1 = iVar7;
              *(bool *)(unaff_EBP + -0xd) = iVar7 != 0;
            }
          }
        }
        else {
          iVar7 = FUN_004deab4(unaff_EBP + -0x15c);
LAB_005a57f3:
          *piVar1 = iVar7;
        }
        if (*piVar1 != 0) {
          iVar7 = *piVar1;
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
          *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(unaff_EBP + 8);
          break;
        }
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    } while (*(int *)(unaff_EBP + -0x18) < 2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006f7690);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

