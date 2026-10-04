
undefined4 FUN_0044aae6(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int extraout_ECX;
  undefined2 extraout_var;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint uVar9;
  uint uVar10;
  int unaff_EBP;
  undefined4 uVar11;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 8);
  iVar7 = *(int *)(iVar3 + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (iVar7 == 0) {
    FUN_0046dae0(0xb,1);
    *(undefined4 *)(iVar3 + 8) = 1;
LAB_0044ad27:
    uVar11 = 2;
  }
  else {
    if (iVar7 == 1) {
      *(undefined4 *)(iVar3 + 8) = 2;
      iVar7 = FUN_00407498((int)*(short *)(iVar3 + 4));
      *(int *)(unaff_EBP + -0x14) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + 8) = 0x17;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
      }
      puVar4 = *(undefined2 **)(unaff_EBP + 0xc);
      uVar11 = FUN_00453181((-((*(byte *)(puVar4 + 2) & 0x20) != 0) & 0x12U) + 7,
                            CONCAT22(extraout_var,*puVar4),0);
      *(undefined4 *)(unaff_EBP + 0xc) = uVar11;
      FUN_004e609e();
      cVar6 = FUN_004cffb7();
      if ((cVar6 != '\0') || ((*(byte *)(puVar4 + 2) & 8) != 0)) {
        cVar6 = FUN_004074bc();
        if ((cVar6 != '\0') || ((*(byte *)(puVar4 + 2) & 8) != 0)) {
LAB_0044ac12:
          FUN_005b8680();
          bVar1 = *(byte *)(puVar4 + 2);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          uVar11 = extraout_ECX_00;
          if ((~bVar1 & 0x40) != 0) {
            uVar11 = 0;
            FUN_0040766a(0x10c,0);
          }
          if (*(char *)((int)puVar4 + 5) != '\0') {
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0x8c) = &PTR_FUN_0066643c;
            puVar5 = *(undefined4 **)(iVar3 + 0xc);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            puVar5 = (undefined4 *)*puVar5;
            uVar11 = FUN_004754d8();
            iVar7 = (*(code *)*puVar5)(uVar11);
            if (iVar7 != 0) {
              FUN_00470383(iVar7,0x131,0);
              iVar7 = FUN_004705f2(*(undefined1 *)((int)puVar4 + 5),0xffffffff);
              if (iVar7 != 0) {
                FUN_005d4bbf(iVar7);
              }
            }
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_00470467();
            uVar11 = extraout_ECX_01;
          }
          uVar8 = 0;
          if (*(int *)(unaff_EBP + -0x1c) != *(int *)(unaff_EBP + -0x20)) {
            uVar8 = FUN_0044bf5a(unaff_EBP + -0x20,iVar3,0,0);
            uVar11 = extraout_ECX_02;
          }
          bVar1 = *(byte *)(puVar4 + 2);
          *(undefined1 *)(unaff_EBP + 8) = 1;
          if ((bVar1 & 8) != 0) {
            *(undefined1 *)(unaff_EBP + 8) = 0;
          }
          uVar9 = CONCAT31((int3)((uint)uVar11 >> 8),bVar1 >> 4) & 0xffffff01;
          uVar10 = CONCAT31((int3)(uVar9 >> 8),bVar1 >> 3) & 0xffffff01;
          FUN_004a6b68(CONCAT31((int3)((uint)uVar8 >> 8),bVar1) & 0xffffff01,
                       *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 8),
                       *(short *)(unaff_EBP + 0xc) * 1000,*(undefined1 *)((int)puVar4 + 3),
                       *(undefined1 *)(puVar4 + 1),
                       CONCAT31((int3)(uVar10 >> 8),(byte)~bVar1 >> 2) & 0xffffff01,uVar10,uVar9,
                       *(undefined4 *)(unaff_EBP + -0x20));
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          goto LAB_0044ad27;
        }
        if (*(short *)(*(int *)(extraout_ECX + 0x118) + 0x12) == 2) {
          iVar7 = FUN_006359f2(extraout_ECX,0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0);
          if ((iVar7 != 0) &&
             ((sVar2 = *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x22),
              *(short *)(iVar7 + 0x606) == sVar2 ||
              ((sVar2 == 0 && (*(short *)(iVar7 + 0x626) != 0)))))) goto LAB_0044ac12;
        }
      }
    }
    uVar11 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar11;
}

