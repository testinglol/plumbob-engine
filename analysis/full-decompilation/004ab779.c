
void FUN_004ab779(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar5;
  float10 fVar6;
  
  FUN_00634c24();
  piVar4 = *(int **)(unaff_EBP + 8);
  iVar3 = piVar4[0x3f];
  *(int *)(unaff_EBP + -0x20) = piVar4[0x3d];
  *(int *)(unaff_EBP + -0x1c) = piVar4[0x3e];
  *(char *)(unaff_EBP + -0x10) = (char)iVar3;
  uVar1 = *(undefined1 *)((int)piVar4 + 0xfd);
  cVar2 = *(char *)((int)piVar4 + 0xfe);
  *(int **)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0xf) = uVar1;
  *(char *)(unaff_EBP + -0xe) = cVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar5 = (int)cVar2;
  iVar3 = (**(code **)(*extraout_ECX + 0x38))();
  *(int *)(unaff_EBP + -0x14) = iVar3;
  if ((((iVar3 < iVar5) || (*(char *)(unaff_EBP + -0x10) < '\x01')) ||
      (iVar3 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar3 <= *(char *)(unaff_EBP + -0x10))) ||
     ((*(char *)(unaff_EBP + -0xf) < '\x01' || (iVar3 <= *(char *)(unaff_EBP + -0xf))))) {
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + 0xb) = 1;
  }
  iVar3 = FUN_006359f2(piVar4,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
  if (iVar3 == 0) {
LAB_004ab83b:
    if (*(char *)(unaff_EBP + 0xb) == '\0') {
LAB_004ab91e:
      (**(code **)(*piVar4 + 0x24))();
      goto LAB_004ab925;
    }
  }
  else if (*(char *)(unaff_EBP + 0xb) == '\0') {
    if (iVar5 == *(int *)(unaff_EBP + -0x14) + 1) {
      *(bool *)(unaff_EBP + 0xb) = *(short *)(iVar3 + 0x5dc) != 0;
      goto LAB_004ab83b;
    }
    goto LAB_004ab91e;
  }
  FUN_0047bd91(unaff_EBP + -0x1c,unaff_EBP + -0x20,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
  fVar6 = (float10)FUN_0046755a(unaff_EBP + -0x20,iVar5);
  FUN_004b4722((float)fVar6);
  (**(code **)(*piVar4 + 0x20))(*(undefined4 *)(unaff_EBP + 0xc));
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))();
  *(int *)(unaff_EBP + -0x40) = extraout_ECX[10];
  *(int *)(unaff_EBP + -0x3c) = extraout_ECX[0xb];
  *(int *)(unaff_EBP + -0x38) = extraout_ECX[0xc];
  *(int *)(unaff_EBP + -0x34) = extraout_ECX[0xd];
  if (piVar4 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar4 + 0x6c))(unaff_EBP + -0x40);
    if (cVar2 != '\0') {
      FUN_00438fc0(unaff_EBP + -0x30,2);
      iVar5 = DAT_006f0084;
      iVar3 = DAT_006f0080;
      if ((*(int *)(unaff_EBP + -0x30) < *(int *)(unaff_EBP + -0x28)) &&
         (*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x24))) {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + DAT_006f0080;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + iVar3;
        *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar5;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar5;
        FUN_004a7901();
        if ((*(int *)(unaff_EBP + -0x30) < *(int *)(unaff_EBP + -0x28)) &&
           (((*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x24) &&
             (*(int *)(*(int *)(unaff_EBP + -0x18) + 0x68) != 0)) && (DAT_006e4870 == '\0')))) {
          FUN_005cf0fa(unaff_EBP + -0x30);
        }
      }
    }
  }
LAB_004ab925:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

