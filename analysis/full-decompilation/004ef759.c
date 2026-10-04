
void FUN_004ef759(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  size_t sVar4;
  undefined3 extraout_var;
  undefined4 uVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  char *_Str;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  uVar3 = (**(code **)(*DAT_006fe8bc + 0x1c))
                    (0,&cITSGraphicSystem::RTTI_Type_Descriptor,
                     &cTSGraphicSystemW95::RTTI_Type_Descriptor,0);
  uVar3 = FUN_006359f2(uVar3);
  piVar1 = DAT_006fe8bc;
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
  (**(code **)(*piVar1 + 0x34))();
  if (((*(int *)(unaff_EBP + -0x1c) == 0) || (*(int *)(unaff_EBP + 8) != 0)) ||
     (DAT_006f29f7 != '\0')) goto LAB_004ef92d;
  if (*(int **)(extraout_ECX + 200) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 200) + 0x98))();
  }
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_005d6516(s_movie_006ca94c,unaff_EBP + -0x28,1);
  if (cVar2 == '\0') {
    FUN_005d499c(extraout_ECX + 0x90);
    if (DAT_006feca4 == 0) {
      cVar2 = *(char *)(DAT_006e486c + 100);
      if (cVar2 < '\t') {
        if (cVar2 == '\b') {
          _Str = s_Music_eag_dn_avi_006ca8d4;
        }
        else if (cVar2 == '\x03') {
          _Str = s_Music_eag_fr_avi_006ca8e8;
        }
        else if (cVar2 == '\x04') {
          _Str = s_Music_eag_de_avi_006ca8fc;
        }
        else if (cVar2 == '\x05') {
          _Str = s_Music_eag_it_avi_006ca910;
        }
        else if (cVar2 == '\x06') {
          _Str = s_Music_eag_sp_avi_006ca924;
        }
        else {
          if (cVar2 != '\a') goto LAB_004ef86a;
          _Str = s_Music_eag_du_avi_006ca938;
        }
      }
      else if (cVar2 == '\t') {
        _Str = s_Music_eag_sw_avi_006ca870;
      }
      else if (cVar2 == '\v') {
        _Str = s_Music_eag_fi_avi_006ca884;
      }
      else if (cVar2 == '\x0e') {
        _Str = s_Music_eag_br_avi_006ca898;
      }
      else if (cVar2 == '\x10') {
        _Str = s_Music_eag_po_avi_006ca8ac;
      }
      else {
LAB_004ef86a:
        _Str = s_Music_eag_us_avi_006ca8c0;
      }
    }
    else {
      FUN_005d499c(extraout_ECX + 0x90);
      _Str = s_Music_simsintro_avi_006ca85c;
    }
    sVar4 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar4);
  }
  FUN_004ef93e(*(undefined4 *)(unaff_EBP + -0x28),unaff_EBP + -0x10,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x10) == 0x280) {
    *(undefined1 *)(unaff_EBP + -0x18) = 0;
  }
  else {
    *(bool *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x10) == 0x140;
  }
  if (*(int *)(unaff_EBP + 8) == 0x1e0) {
    *(undefined1 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    *(bool *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8) == 0xf0;
  }
  uVar5 = CONCAT31(extraout_var,DAT_006f29f8);
  uVar3 = *(undefined4 *)(unaff_EBP + -0x28);
  uVar10 = *(undefined4 *)(unaff_EBP + -0x14);
  uVar9 = *(undefined4 *)(unaff_EBP + -0x18);
  uVar8 = *(undefined4 *)(unaff_EBP + 8);
  uVar7 = *(undefined4 *)(unaff_EBP + -0x10);
  uVar6 = FUN_004efa01(uVar7,uVar8,uVar9,uVar10,uVar5);
  FUN_005f00c5(uVar3,uVar6,uVar7,uVar8,uVar9,uVar10,uVar5);
  DAT_006feca4 = DAT_006feca4 + 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_004ef92d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

