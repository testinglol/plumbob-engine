
void __thiscall FUN_0046ceb8(undefined4 *param_1,undefined4 *param_2)

{
  HGDIOBJ pvVar1;
  
  pvVar1 = (HGDIOBJ)*param_1;
  if (pvVar1 != (HGDIOBJ)0x0) {
    if (param_2 == (undefined4 *)0x0) {
      SelectObject(DAT_006e48bc,pvVar1);
    }
    else {
      pvVar1 = SelectObject(DAT_006e48bc,pvVar1);
      *param_2 = pvVar1;
    }
  }
  return;
}

