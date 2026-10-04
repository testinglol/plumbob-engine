
bool FUN_005bc1a2(void)

{
  BOOL BVar1;
  int extraout_ECX;
  int unaff_EBP;
  bool bVar2;
  
  FUN_00634c24();
  if ((*(int *)(extraout_ECX + 8) == 0) && (FUN_005bc10b(), *(int *)(extraout_ECX + 8) == 0)) {
    bVar2 = false;
  }
  else {
    wsprintfA((LPSTR)(unaff_EBP + -0x128),s__StringFileInfo__04lx_04lx__s_006d2578,
              (uint)**(ushort **)(extraout_ECX + 0xc),(uint)(*(ushort **)(extraout_ECX + 0xc))[1],
              s_FileVersion_006d2598);
    BVar1 = VerQueryValueA(*(LPCVOID *)(extraout_ECX + 8),(LPCSTR)(unaff_EBP + -0x128),
                           (LPVOID *)(unaff_EBP + -0x10),(PUINT)(unaff_EBP + -0x14));
    bVar2 = BVar1 != 0;
    if (bVar2) {
      FUN_005bad81(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005bc346(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined ***)(unaff_EBP + -0x28) = &PTR_LAB_0066933c;
      FUN_00401729();
    }
    else {
      FUN_00406466(0,DAT_00666580);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar2;
}

