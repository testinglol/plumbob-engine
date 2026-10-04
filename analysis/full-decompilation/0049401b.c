
void FUN_0049401b(void)

{
  undefined1 uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x40) = extraout_ECX;
  *(int *)(unaff_EBP + -0x30) = (int)*(char *)(extraout_ECX + 0xe02e);
  iVar4 = FUN_00401f73();
  if ((iVar4 == 0) && (*(char *)(extraout_ECX + 0xe024) == '\0')) goto LAB_00494249;
  iVar5 = FUN_00493133();
  iVar4 = DAT_006e54d8;
  if (iVar5 != 0) goto LAB_00494249;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  iVar4 = *(int *)(iVar4 + 0x10);
  *(int *)(unaff_EBP + -0x38) = iVar4;
  iVar5 = extraout_ECX;
  if (0 < iVar4) {
    *(int *)(unaff_EBP + -0x34) = extraout_ECX + 0x24;
    do {
      cVar3 = *(char *)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(int *)(unaff_EBP + -0x3c) = *(char *)(unaff_EBP + -0x30) * 4 + 0x40;
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x34);
      do {
        _memset((void *)(unaff_EBP + -0x50),0,0xe);
        *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x1c);
        *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x30);
        iVar4 = *(int *)(*(int *)(*(int *)(unaff_EBP + -0x3c) + DAT_006e54dc) + 0xc);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        puVar7 = (undefined4 *)(*(int *)(iVar4 + cVar3 * 4) + *(char *)(unaff_EBP + -0x20) * 0xe);
        *(undefined4 *)(unaff_EBP + -0x50) = *puVar7;
        *(undefined4 *)(unaff_EBP + -0x4c) = puVar7[1];
        *(undefined4 *)(unaff_EBP + -0x48) = puVar7[2];
        *(undefined2 *)(unaff_EBP + -0x44) = *(undefined2 *)(puVar7 + 3);
        puVar7 = *(undefined4 **)(unaff_EBP + -0x2c);
        iVar4 = _memcmp((void *)(unaff_EBP + -0x50),puVar7,0xe);
        if (iVar4 != 0) {
          puVar8 = (undefined4 *)
                   (*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x40 +
                                              *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
                            *(char *)(unaff_EBP + -0x14) * 4) + *(char *)(unaff_EBP + -0x13) * 0xe);
          *(undefined4 *)(unaff_EBP + -0x28) = 0xffffffff;
          *puVar8 = *puVar7;
          puVar8[1] = puVar7[1];
          puVar8[2] = puVar7[2];
          *(undefined2 *)(puVar8 + 3) = *(undefined2 *)(puVar7 + 3);
          do {
            *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
            cVar2 = *(char *)(unaff_EBP + -0x20) + *(char *)(unaff_EBP + -0x28);
            *(char *)(unaff_EBP + -0xd) = cVar2;
            while( true ) {
              *(char *)(unaff_EBP + -0x17) = cVar2;
              *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(unaff_EBP + -0x30);
              *(char *)(unaff_EBP + -0x18) =
                   *(char *)(unaff_EBP + -0x1c) + *(char *)(unaff_EBP + -0x24);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              puVar6 = (undefined1 *)FUN_00479dca(unaff_EBP + -0xe,unaff_EBP + -0x18);
              iVar4 = *(int *)(DAT_006e54dc + 0x48 + *(char *)(unaff_EBP + -0x16) * 4);
              *(undefined1 *)(unaff_EBP + -4) = 0;
              iVar4 = *(int *)(*(int *)(iVar4 + 0xc) + *(char *)(unaff_EBP + -0x18) * 4);
              uVar1 = *puVar6;
              *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
              iVar5 = *(int *)(unaff_EBP + -0x24);
              *(undefined1 *)(iVar4 + *(char *)(unaff_EBP + -0x17)) = uVar1;
              if (1 < iVar5) break;
              cVar2 = *(char *)(unaff_EBP + -0xd);
            }
            *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
          } while (*(int *)(unaff_EBP + -0x28) < 2);
          puVar7 = *(undefined4 **)(unaff_EBP + -0x2c);
          *puVar7 = *(undefined4 *)(unaff_EBP + -0x50);
          puVar7[1] = *(undefined4 *)(unaff_EBP + -0x4c);
          puVar7[2] = *(undefined4 *)(unaff_EBP + -0x48);
          *(undefined2 *)(puVar7 + 3) = *(undefined2 *)(unaff_EBP + -0x44);
          FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
          FUN_00492be0(unaff_EBP + -0x14);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
        *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 0xe;
      } while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x38));
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 0x380;
    } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x38));
    iVar5 = *(int *)(unaff_EBP + -0x40);
  }
  FUN_00492bba(*(undefined4 *)(iVar5 + 0xe028));
  iVar4 = FUN_00401f73();
  if (iVar4 == 0) {
    cVar3 = (**(code **)(**(int **)(iVar5 + 0xe044) + 100))();
    if (cVar3 != '\0') goto LAB_0049421c;
  }
  else {
LAB_0049421c:
    FUN_00492bc4();
    FUN_0040766a(0x91,0);
    FUN_0040766a(0x101,0);
  }
  FUN_0049315a();
LAB_00494249:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

