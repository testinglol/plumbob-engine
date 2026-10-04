
void FUN_005a47ae(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(uint *)(unaff_EBP + 0xc) = (uint)(*(char *)(unaff_EBP + 0xc) != '\0');
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  cVar4 = FUN_005a4684();
  if (cVar4 != '\0') {
    FUN_00431779(extraout_ECX[0x89] + extraout_ECX[0x8e],
                 extraout_ECX[0x8f] + extraout_ECX[0x89] + extraout_ECX[0x8e]);
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    FUN_005d4956(&DAT_006c3d7c);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005d4956(&DAT_006c4a1c);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    do {
      uVar5 = FUN_005d4be4(unaff_EBP + -0x88,1);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      cVar4 = FUN_005d49dc(uVar5);
      if (cVar4 == '\0') {
        uVar5 = FUN_005d4be4(unaff_EBP + -0x34,1);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        cVar4 = FUN_005d49dc(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005b8770();
        bVar3 = false;
        if (cVar4 != '\0') goto LAB_005a48ca;
      }
      else {
LAB_005a48ca:
        bVar3 = true;
      }
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005b8770();
      if (!bVar3) goto LAB_005a4911;
      uVar5 = FUN_005d4c15(unaff_EBP + -0x4c,
                           (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) + -1);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005d499c(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005b8770();
    } while( true );
  }
  FUN_005d5156(unaff_EBP + -0x28,s_No_ResID_Token_in_Resource_Senta_006d1f68);
  FUN_00575805(unaff_EBP + -0x28);
  goto LAB_005a4ba4;
LAB_005a4911:
  uVar5 = FUN_005d4c15(unaff_EBP + -0x88,1);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  cVar4 = FUN_005d49dc(uVar5);
  if (cVar4 == '\0') {
    uVar5 = FUN_005d4c15(unaff_EBP + -0x34,1);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    cVar4 = FUN_005d49dc(uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005b8770();
    bVar3 = false;
    if (cVar4 != '\0') goto LAB_005a495e;
  }
  else {
LAB_005a495e:
    bVar3 = true;
  }
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  if (!bVar3) goto LAB_005a49a5;
  uVar5 = FUN_005d4be4(unaff_EBP + -0x4c,
                       (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) + -1);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_005d499c(uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  goto LAB_005a4911;
LAB_005a49a5:
  cVar4 = FUN_005a4bf1(unaff_EBP + -0x18,unaff_EBP + -0x1c);
  if (cVar4 == '\0') {
    iVar6 = (*(code *)PTR_FUN_006d7014)(*(undefined4 *)(unaff_EBP + -0x18));
    if (iVar6 != 0) {
      *(int *)(unaff_EBP + -0x1c) = iVar6;
      goto LAB_005a49df;
    }
    FUN_005d5156(unaff_EBP + -0x28,s_ResID__s_has_no_known_value_in_R_006d1f34,
                 *(undefined4 *)(unaff_EBP + -0x18));
LAB_005a49fd:
    FUN_00575805(unaff_EBP + -0x28);
  }
  else {
LAB_005a49df:
    uVar5 = *(undefined4 *)(unaff_EBP + -0x1c);
    cVar4 = FUN_005a4684();
    if (cVar4 == '\0') {
      FUN_005d5156(unaff_EBP + -0x28,s_No_Location_String_in_Resource_S_006d1f0c);
      goto LAB_005a49fd;
    }
    FUN_00431779(extraout_ECX[0x89] + extraout_ECX[0x8e],
                 extraout_ECX[0x8f] + extraout_ECX[0x89] + extraout_ECX[0x8e]);
    iVar6 = 0;
    cVar4 = FUN_005a4684();
    if (cVar4 == '\0') {
LAB_005a4ab1:
      if (((iVar6 == 0) || (iVar6 == *(char *)(DAT_006e486c + 100))) && (*extraout_ECX != 0)) {
        FUN_005d48d9();
        *(undefined1 *)(unaff_EBP + -0x8c) = *(undefined1 *)(unaff_EBP + 0xc);
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_005d499c(unaff_EBP + -0x40);
        *(undefined4 *)(unaff_EBP + -0x48) = uVar5;
        *(char *)(unaff_EBP + -0x44) = (char)iVar6;
        FUN_005a3f6a(unaff_EBP + -0x84,unaff_EBP + -0x48);
        if (*(int *)(unaff_EBP + -0x84) == 0) {
          *(undefined4 *)(unaff_EBP + -0xb0) = *(undefined4 *)(unaff_EBP + -0x48);
          *(undefined1 *)(unaff_EBP + -0xac) = *(undefined1 *)(unaff_EBP + -0x44);
          FUN_005b86bd(unaff_EBP + -0x98);
          *(undefined1 *)(unaff_EBP + -0x9c) = *(undefined1 *)(unaff_EBP + -0x8c);
          iVar6 = *extraout_ECX;
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          FUN_005a5194(*(int *)(iVar6 + 0x10) + 1);
          FUN_005a5117(unaff_EBP + -0xbc,unaff_EBP + -0xb0);
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          FUN_005b8770();
        }
        *(undefined1 *)(unaff_EBP + -4) = 6;
        goto LAB_005a4b87;
      }
    }
    else {
      FUN_005d48d9();
      iVar6 = extraout_ECX[0x89];
      iVar1 = extraout_ECX[0x8f];
      iVar2 = extraout_ECX[0x8e];
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      FUN_00431779(iVar6 + iVar2,iVar1 + iVar6 + iVar2);
      cVar4 = FUN_005a4bf1(unaff_EBP + -0x34,unaff_EBP + -0x1c);
      if (cVar4 != '\0') {
        iVar6 = *(int *)(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8770();
        goto LAB_005a4ab1;
      }
      FUN_005d5156(unaff_EBP + -0x28,s_Res_Language__s_has_no_known_val_006d1ed4,
                   *(undefined4 *)(unaff_EBP + -0x34));
      FUN_00575805(unaff_EBP + -0x28);
      *(undefined1 *)(unaff_EBP + -4) = 6;
LAB_005a4b87:
      FUN_005b8770();
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
LAB_005a4ba4:
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

