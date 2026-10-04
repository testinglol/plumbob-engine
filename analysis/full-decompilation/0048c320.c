
undefined4 FUN_0048c320(short param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_006e5790;
  if (param_1 != 0) {
    for (; puVar1 != DAT_006e5794; puVar1 = puVar1 + 1) {
      if (*(short *)*puVar1 == param_1) {
        return *puVar1;
      }
    }
  }
  return 0;
}

