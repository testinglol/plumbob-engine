
void FUN_00570d92(void)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined1 uVar8;
  int unaff_EBP;
  int iVar9;
  undefined4 uStack_44;
  
  FUN_00634c24();
  uStack_44 = 0x570da7;
  piVar4 = (int *)FUN_004a69e9();
  uStack_44 = 1;
  *(undefined2 *)(unaff_EBP + -0x24) = 0;
  *(undefined2 *)(unaff_EBP + -0x22) = 0;
  FUN_004a6a9d(unaff_EBP + -0x40,unaff_EBP + -0x24);
  uStack_44 = 0x570dca;
  uVar5 = FUN_004a696f();
  *(undefined4 *)(unaff_EBP + -0x28) = uVar5;
  uVar8 = (undefined1)(*(int *)(unaff_EBP + -0x3c) >> 4);
  *(undefined1 *)(unaff_EBP + -0x1c) = uVar8;
  *(char *)(unaff_EBP + -0x1b) = (char)(*(int *)(unaff_EBP + -0x40) >> 4);
  *(char *)(unaff_EBP + -0x1a) = (char)uVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_44 = 0x570dea;
  bVar2 = FUN_004a694e();
  *(int *)(unaff_EBP + -0x30) = piVar4[1] / (4 << (bVar2 & 0x1f));
  uStack_44 = 0x570e01;
  bVar2 = FUN_004a694e();
  iVar7 = *piVar4;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -0x10) = uVar8;
  *(int *)(unaff_EBP + -0x34) = iVar7 / (0x10 << (bVar2 & 0x1f));
  *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(unaff_EBP + -0x1b);
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + -0x28);
  iVar9 = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar7 = DAT_006e54d8;
  if (0 < *(int *)(unaff_EBP + -0x30)) {
    *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x28);
    do {
      cVar3 = *(char *)(unaff_EBP + -0xf);
      *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x10);
      *(char *)(unaff_EBP + -0x13) = cVar3;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (0 < *(int *)(unaff_EBP + -0x34)) {
        *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x34);
        do {
          cVar1 = *(char *)(unaff_EBP + -0x14);
          if ((((*(int *)(iVar7 + 0x70) + 1 <= (int)cVar1) &&
               ((int)cVar1 <= *(int *)(iVar7 + 0x74) + -1)) &&
              (*(int *)(iVar7 + 0x78) + 1 <= (int)cVar3)) &&
             ((int)cVar3 <= *(int *)(iVar7 + 0x7c) + -1)) {
            *(undefined4 **)(unaff_EBP + -0x38) = &uStack_44;
            uStack_44._3_1_ = (undefined1)((uint)iVar7 >> 0x18);
            uStack_44._0_3_ =
                 CONCAT12(*(undefined1 *)(unaff_EBP + -0x28),
                          CONCAT11(cVar3,*(undefined1 *)(unaff_EBP + -0x14)));
            uVar6 = FUN_004893e4();
            if ((uVar6 & 4) == 0) {
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
              iVar7 = DAT_006e54d8;
            }
            else {
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
              iVar7 = DAT_006e54d8;
            }
          }
          *(char *)(unaff_EBP + -0x14) = cVar1 + '\x01';
          cVar3 = cVar3 + -1;
          piVar4 = (int *)(unaff_EBP + -0x2c);
          *piVar4 = *piVar4 + -1;
          *(char *)(unaff_EBP + -0x13) = cVar3;
        } while (*piVar4 != 0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      bVar2 = (byte)iVar9;
      *(byte *)(unaff_EBP + -0x10) = (bVar2 & 1) + *(char *)(unaff_EBP + -0x10);
      iVar9 = iVar9 + 1;
      *(byte *)(unaff_EBP + -0xf) = (bVar2 - 1 & 1) + *(char *)(unaff_EBP + -0xf);
    } while (iVar9 < *(int *)(unaff_EBP + -0x30));
  }
  *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x18);
  uStack_44 = 0x570f0e;
  __ftol();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

