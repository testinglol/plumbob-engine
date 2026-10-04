
void FUN_0056d52d(void)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int *extraout_ECX;
  uint uVar7;
  undefined4 uVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar6 = *(int *)(*(int *)(unaff_EBP + 8) + 0xdc);
  sVar2 = FUN_00440b6d(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x11c));
  uVar7 = (uint)sVar2;
  uVar8 = 0;
  if ((0 < (int)uVar7) && (uVar7 < (*(int *)(iVar6 + 0x1c) - *(int *)(iVar6 + 0x18) >> 2) + 1U)) {
    uVar8 = *(undefined4 *)(*(int *)(iVar6 + 0x18) + -4 + uVar7 * 4);
  }
  piVar3 = (int *)FUN_006359f2(uVar8,0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0);
  extraout_ECX[0x6a] = (int)piVar3;
  piVar4 = (int *)(**(code **)(*piVar3 + 0x8c))();
  (**(code **)(*piVar4 + 0x50))(0);
  iVar6 = *(int *)(unaff_EBP + 0xc);
  uVar8 = 0;
  extraout_ECX[0x6c] = iVar6;
  *(short *)(piVar3 + 0x167) = (short)iVar6;
  (**(code **)(*piVar3 + 0x8c))(0);
  FUN_0058a17c(uVar8);
  pvVar5 = operator_new(0x98);
  *(void **)(unaff_EBP + 8) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_00408b9d();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = piVar3[0x47];
  extraout_ECX[0x6b] = iVar6;
  FUN_00409377(iVar1,piVar3);
  if (((uint)(int)*(short *)((int)piVar3 + 0x60e) >> 1 & 1) == 0) {
    if (((uint)(int)*(short *)((int)piVar3 + 0x60e) >> 2 & 1) == 0) {
      if (((short)piVar3[0x180] == 0) || (0x11 < (short)piVar3[0x180])) {
        *(undefined1 *)((int)extraout_ECX + 0x222) = 1;
        FUN_0056df70();
      }
      else {
        *(undefined1 *)((int)extraout_ECX + 0x223) = 1;
        FUN_0056de93();
      }
    }
    else {
      *(undefined1 *)((int)extraout_ECX + 0x221) = 1;
      *(undefined1 *)(extraout_ECX + 0x88) = 0;
      FUN_0056dd16();
    }
  }
  else {
    *(undefined1 *)(extraout_ECX + 0x88) = 1;
    *(undefined1 *)((int)extraout_ECX + 0x221) = 0;
    FUN_0056dbcc();
  }
  (**(code **)(*extraout_ECX + 0x168))();
  extraout_ECX[0x8a] = -1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x65) = 1;
  return;
}

