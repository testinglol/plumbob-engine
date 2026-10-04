
void __fastcall FUN_0046ce6a(undefined4 *param_1)

{
  HGDIOBJ ho;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((*(short *)(param_1 + 2) != 0) &&
     (ho = (HGDIOBJ)*param_1, puVar2 = DAT_006e5454, ho != (HGDIOBJ)0x0)) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
      if ((puVar2 != param_1) && ((HGDIOBJ)*puVar2 == ho)) goto LAB_0046ce97;
    }
    DeleteObject(ho);
  }
LAB_0046ce97:
  puVar2 = &DAT_006e5454;
  puVar1 = DAT_006e5454;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    if (puVar1 == param_1) break;
    puVar2 = puVar1 + 1;
    puVar1 = (undefined4 *)puVar1[1];
  }
  *puVar2 = param_1[1];
  return;
}

